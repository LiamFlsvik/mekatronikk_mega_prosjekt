#!/usr/bin/env python3

from enum import Enum, auto
import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup

from process_msgs.msg  import KeyEvent, SceneState, Task, TaskFeedback
from process_msgs.srv  import GetScene

class Phase(Enum):
    IDLE         = auto()
    MOVE_HOME    = auto()
    SCAN         = auto()
    VERIFY_CUBES = auto()
    POINT        = auto()
    DONE         = auto()
    HALTED       = auto()

# ==================================
class ProcessHandler(Node):
    """
    Simple event-driven FSM that:
      • waits for keyboard 'w' to start
      • walks through MOVE_HOME → SCAN → VERIFY → POINT
      • repeats SCAN if cubes missing
      • aborts instantly on emergency stop
    """

    def __init__(self) -> None:
        super().__init__('process_handler')

        self.cb_group = ReentrantCallbackGroup()

        # ---- publishers / subscribers ------------------------
        self.task_pub = self.create_publisher(Task,
                                              '/task_command',
                                              10)

        self.create_subscription(KeyEvent,
                                 '/active_keys',
                                 self.on_keys,
                                 10,
                                 callback_group=self.cb_group)

        self.create_subscription(SceneState,
                                 '/scene/state',
                                 self.on_scene,
                                 10,
                                 callback_group=self.cb_group)

        self.create_subscription(TaskFeedback,
                                 '/task/feedback',
                                 self.on_task_feedback,
                                 10,
                                 callback_group=self.cb_group)

        # ---- service server ----------------------------------
        self.create_service(GetScene,
                            'GetScene',
                            self.handle_get_scene,
                            callback_group=self.cb_group)

        # ---- state -------------------------------------------
        self.phase            = Phase.IDLE
        self.last_scene       = None
        self.in_flight_task   = None         # command string
        self.emergency_stop   = False

        self.get_logger().info('process_handler ready – waiting for start (press W)')

    # =========================================================
    #  Call-backs
    # =========================================================
    def on_keys(self, msg: KeyEvent) -> None:
        # emergency stop wins over everything
        if msg.emergency_stop and not self.emergency_stop:
            self.emergency_stop = True
            self.abort('Emergency stop engaged')
            return

        if self.phase == Phase.IDLE and 'w' in msg.active_keys:
            self.advance_to(Phase.MOVE_HOME)

    # ---------------------------------------------------------
    def on_scene(self, msg: SceneState) -> None:
        self.last_scene = msg
        # Only relevant when we are waiting in VERIFY_CUBES
        if self.phase == Phase.VERIFY_CUBES:
            self.evaluate_cubes()

    # ---------------------------------------------------------
    def on_task_feedback(self, fb: TaskFeedback) -> None:
        if self.phase == Phase.HALTED:
            return                       # ignore everything when halted

        if fb.success:
            self.get_logger().info(f"✓ Task '{fb.command}' completed")
            # Normal flow – move on to the next phase
            if self.phase == Phase.MOVE_HOME:
                self.advance_to(Phase.SCAN)
            elif self.phase == Phase.SCAN:
                self.advance_to(Phase.VERIFY_CUBES)
            elif self.phase == Phase.POINT:
                self.advance_to(Phase.DONE)
        else:
            self.abort(f"Task '{fb.command}' failed: {fb.message}")

    # =========================================================
    #  FSM helpers
    # =========================================================
    def advance_to(self, new_phase: Phase) -> None:
        """
        Transition helper: updates phase and sends the corresponding Task.
        """
        self.phase = new_phase
        self.get_logger().info(f'→ Phase: {self.phase.name}')

        task_map = {
            Phase.MOVE_HOME: 'MOVE_HOME',
            Phase.SCAN:      'SCAN',
            Phase.POINT:     'POINT',
        }

        if new_phase in task_map:
            self.send_task(task_map[new_phase])

        if new_phase == Phase.VERIFY_CUBES:
            self.evaluate_cubes()
        elif new_phase == Phase.DONE:
            self.get_logger().info('🎉 Sequence finished – waiting for new start (press W)')
            self.phase = Phase.IDLE      # reset FSM

    # ---------------------------------------------------------
    def send_task(self, command: str) -> None:
        t = Task()
        t.command = command
        self.task_pub.publish(t)
        self.in_flight_task = command
        self.get_logger().info(f'→ Sent task: {command}')

    # ---------------------------------------------------------
    def evaluate_cubes(self) -> None:
        """
        Decide whether to continue or rescan based on SceneState.
        """
        if not self.last_scene:
            return                      # wait for first SceneState

        if self.last_scene.cubes_complete:
            self.get_logger().info('All cubes located ✔')
            self.advance_to(Phase.POINT)
        else:
            self.get_logger().warn('Cubes missing – rescanning')
            self.advance_to(Phase.SCAN)

    # ---------------------------------------------------------
    def abort(self, reason: str) -> None:
        self.phase = Phase.HALTED
        self.get_logger().error(f'‼️ ABORT: {reason}')
        # Optionally publish a STOP task or inform robot_controller here

    # =========================================================
    #  Service handler
    # =========================================================
    def handle_get_scene(self, request, response):
        response.scene = self.last_scene if self.last_scene else SceneState()
        return response


# =============================================================
def main(args=None):
    rclpy.init(args=args)
    node = ProcessHandler()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()