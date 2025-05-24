### About the project
The project is developed in the engineering course **Mechatronics and Robotics** at NTNU in Ålesund.  
The main goal of the project is to learn how to apply the MoveIt 2 framework along with ROS 2 in order to control robots.

The order of operations for the robot in the project is as follows:

1. Move the robot to a home position.  
2. Perform a scan of the robot’s environment.  
3. Locate and identify three cubes of different colors (red, yellow and blue).  
4. Reassure that all cubes are found; if not, notify the operator and redo the location and identification.  
5. Move above the cubes and “point” at them.  

---

### Prerequisites
MoveIt 2 must be downloaded, built and sourced. Follow the details in the official tutorial:

> https://moveit.picknik.ai/main/doc/tutorials/getting_started/getting_started.html#create-a-colcon-workspace-and-download-tutorials

Furthermore, the Universal Robot ROS 2 Driver must be set up. See the link below for instructions:

> https://github.com/UniversalRobots/Universal_Robots_ROS2_Driver/tree/main

---

# UR-Robot Cube-Handling Pipeline  

```mermaid
flowchart TB
  %% ========================= VISION =========================
  subgraph Vision
    CAM[usb_camera] -->|"🟢 /camera/image_raw (sensor_msgs/Image)"| PROC[camera_processor]
    PROC -->|"🟢 /cubes/detections (process_msgs/CubeArray)"| SCENE(scene_handler)
  end

  %% ========================= LOGIC ==========================
  subgraph Logic
    INPUT[input_handler] -->|"🟢 /active_keys (process_msgs/KeyEvent)"| FSM[process_handler]
    SCENE -->|"🟢 /scene/state (process_msgs/SceneState)"| FSM
    FSM -->|"🟢 /task_command (process_msgs/Task)"| CTRL[robot_controller]
    CTRL -->|"🟢 /task/feedback (process_msgs/TaskFeedback)"| FSM
  end

  %% ========================= MOTION =========================
  subgraph Motion
    CTRL -. "⚫ plan() / execute()" .-> MOVEIT[move_group]
    MOVEIT -->|"🟢 /joint_trajectory (trajectory_msgs/JointTrajectory)"| UR[ur_driver]
    CTRL -->|"🟢 /joint_states (sensor_msgs/JointState)"| SCENE
  end

  %% ========================= SERVICES =========================
  FSM -->|"🔵 GetScene (service: SceneState)"| SCENE
