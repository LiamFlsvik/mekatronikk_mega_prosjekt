# Megaprosjekt – AIS2105

This repository contains a **complete MoveIt 2 + ROS 2 pipeline** that lets a UR‑manipulator find, identify and point at three coloured cubes on a table – from keyboard trigger to camera vision, planning scene updates and motion execution.

---

[EXAMPLE VIDEO RUN DARK](images/example_run_dark.mp4)

[EXAMPLE VIDEO RUN LIGHT](images/example_run_light.mp4)


---

## Project Flow

1. **Home** – robot drives to a safe joint pose.  
2. **Scan** – wrist‑mounted camera sweeps a half‑circle above the workspace.  
3. **Detect cubes** – vision node publishes pixel‑space coordinates of *red*, *yellow*, *blue*, *green* cubes.  
4. **Verify** – scene handler transforms detections to base frame and injects virtual boxes into MoveIt.  
5. **Point** – robot hovers above every cube in turn.  
6. **Done** – cycle can be restarted or paused with keyboard shortcuts.

---

## Prerequisites

| Software | Tested Version | Install Guide |
|----------|---------------|---------------|
| **ROS 2** | Jazzy | <https://docs.ros.org/en/jazzy/Installation.html> |
| **MoveIt 2** | Jazzy | <https://moveit.picknik.ai/main/index.html> | |
| **UR ROS 2 Driver** | - | <https://github.com/UniversalRobots/Universal_Robots_ROS2_Driver> |
| **OpenCV + cvzone** | - | `pip3 install cvzone` |
| **TMUX (optional)** | - | `sudo apt install tmux` |

After installing, **source** both ROS 2 and MoveIt 2 setups:

```bash
source /opt/ros/iron/setup.bash
source ~/moveit2_ws/install/setup.bash
```

---

## Quick Start

Clone inside a workspace and build:

```bash
cd ~/ws_mega_prosjekt/src
git clone https://github.com/LiamFlsvik/mekatronikk_mega_prosjekt.git
cd ..
colcon build
source install/setup.bash
```

Run the full stack **in one terminal**:

```bash
ros2 launch bringup_robot bringup_robot.launch.py
```

…or with TMUX (Recommended):

```bash
./bringup_robot/scripts/bringup_tmux.sh
```

Press **W** to kick off the sequence, **Space** for emergency stop, **Enter** to pause / resume.

---

## Package Overview

| Package | Purpose |
|---------|---------|
| **process_msgs** | Custom message & service definitions |
| **input_handler** | Captures keyboard keys and publishes `KeyEvent` |
| **camera_processor** | OpenCV cube detection → `CubeArray` |
| **scene_handler** | Converts pixels to base‑frame boxes, updates planning scene |
| **robot_controller** | Executes `MOVE_HOME`, `SCAN`, `VERIFY_CUBES` via MoveIt |
| **process_handler** | High‑level state machine that orchestrates the tasks |
| **bringup_robot** | Launches everything (plain ROS 2 launch or TMUX helper) |

---

## Building Individual Packages

Need to tweak just one node? Example for the vision stack:

```bash
colcon build --packages-select camera_processor scene_handler
source install/setup.bash
```

---

## Troubleshooting Tips

* **No `/active_keys`** – ensure the terminal running `keyboard_input_handler` has focus.  
* **Plan failed** – increase `scan_height` or clear obstacles in RViz Planning Scene.  
* **Boxes jitter** – lower `camera_filter_position_filter_strenght` (`ros2 param set …`).  

Each sub‑package README dives deeper into its own troubleshooting matrix.

---

## Repository Layout (truncated)

```
megaprosjekt_ws/src/
 ├─ bringup_robot/          ← one‑shot launch helpers
 ├─ camera_processor/       ← cube_tracker vision node
 ├─ input_handler/          ← keyboard interface
 ├─ process_handler/        ← state machine
 ├─ process_msgs/           ← custom interfaces
 ├─ robot_controller/       ← MoveIt commander
 └─ scene_handler/          ← camera→base transform & planning scene
```

---
