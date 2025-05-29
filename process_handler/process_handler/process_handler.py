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
    PAUSED       = auto()

class ProcessHandler(Node):
    def __init__(self) -> None:
        super().__init__('process_handler')

        self.cb_group = ReentrantCallbackGroup()

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

        self.create_service(GetScene,
                            'GetScene',
                            self.handle_get_scene,
                            callback_group=self.cb_group)

        self.phase            = Phase.IDLE
        self.last_scene       = None
        self.in_flight_task   = None
        self.emergency_stop   = False
        self.paused_phase = None

        self.get_logger().info('process_handler ready – press W to start, Enter to pause/resume')

    def on_keys(self, msg: KeyEvent) -> None:
        if '<space>' in msg.active_keys and not self.emergency_stop:
            self.emergency_stop = True
            self.abort('Emergency stop engaged')
            return

        keys = msg.active_keys

        if self.phase == Phase.IDLE and 'w' in keys:
            self.advance_to(Phase.MOVE_HOME)
            return

        if 'enter' in keys:
            if self.phase in [Phase.MOVE_HOME, Phase.SCAN, Phase.VERIFY_CUBES, Phase.POINT]:
                self.paused_phase = self.phase
                self.phase = Phase.PAUSED
                self.get_logger().warn('Paused')
            elif self.phase == Phase.PAUSED:
                self.phase = self.paused_phase
                self.get_logger().info(f'Resumed: {self.phase.name}')

    def on_scene(self, msg: SceneState) -> None:
        if self.phase == Phase.PAUSED:
            return

        self.last_scene = msg

        if self.phase == Phase.VERIFY_CUBES:
            self.evaluate_cubes()

    def on_task_feedback(self, fb: TaskFeedback) -> None:
        if self.phase in [Phase.HALTED, Phase.PAUSED]:
            return
        
        if fb.success:
            self.get_logger().info(f"✓ Task '{fb.command}' completed")
            if self.phase == Phase.MOVE_HOME:
                self.advance_to(Phase.SCAN)
            elif self.phase == Phase.SCAN:
                self.advance_to(Phase.VERIFY_CUBES)
            elif self.phase == Phase.POINT:
                self.advance_to(Phase.DONE)
        else:
            self.abort(f"Task '{fb.command}' failed: {fb.message}")

    def advance_to(self, new_phase: Phase) -> None:
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
            self.get_logger().info('Sequence finished, waiting for new start (press W)')
            self.phase = Phase.IDLE

    def send_task(self, command: str) -> None:
        t = Task()
        t.command = command
        self.task_pub.publish(t)
        self.in_flight_task = command
        self.get_logger().info(f'→ Sent task: {command}')

    def evaluate_cubes(self) -> None:
        if not self.last_scene:
            return

        if self.last_scene.cubes_complete:
            self.get_logger().info('All cubes located')
            self.advance_to(Phase.POINT)
        else:
            self.get_logger().warn('Cubes missing – rescanning')
            self.advance_to(Phase.SCAN)

    def abort(self, reason: str) -> None:
        self.phase = Phase.HALTED
        self.get_logger().error(f'ABORT: {reason}')

    def handle_get_scene(self, request, response):
        response.scene = self.last_scene if self.last_scene else SceneState()
        return response

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