# UR-Robot Cube-Handling Pipeline  
ROS 2 **Jazzy** – communication & integration guide

```mermaid
flowchart LR
  %% ========================= VISION =========================
  subgraph Vision
    CAM[usb_camera] -->|🟢 /camera/image_raw<br><b>sensor_msgs/Image</b>| PROC[camera_processor]
    PROC -->|🟢 /cubes/detections<br><b>process_msgs/CubeArray</b>| SCENE(scene_handler)
  end

  %% ========================= LOGIC ==========================
  subgraph Logic
    INPUT[input_handler] -->|🟢 /active_keys<br><b>process_msgs/KeyEvent</b>| FSM[process_handler]
    SCENE -->|🟢 /scene/state<br><b>process_msgs/SceneState</b>| FSM
    FSM -->|🟢 /task_command<br><b>process_msgs/Task</b>| CTRL[robot_controller]
    CTRL -->|🟢 /task/feedback<br><b>process_msgs/TaskFeedback</b>| FSM
  end

  %% ========================= MOTION =========================
  subgraph Motion
    CTRL -. ⚫ plan() / execute() .-> MOVEIT[move_group]
    MOVEIT -->|🟢 /joint_trajectory<br><b>trajectory_msgs/JointTrajectory</b>| UR[ur_driver]
    CTRL -->|🟢 /joint_states<br><b>sensor_msgs/JointState</b>| SCENE
  end

  %% ========================= SERVICES ========================
  FSM -->|"🔵 GetScene (service)\nSceneState"| SCENE
