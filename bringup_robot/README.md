# **bringup_robot**

`bringup_robot` is the convenience package that launches **every core node** of the Megaprosjekt stack in one go.  
It offers two entry points:

1. **ROS launch graph** – `bringup_robot.launch.py` starts each subsystem in a single process tree.  
2. **TMUX session** – `scripts/bringup_tmux.sh` opens a pane per launch file so you can watch logs independently and kill the whole system with one `Ctrl‑C`.

---

### What Gets Started

| Pane / Launch | Node group | Package           | Executable / Launch |
|---------------|-----------|-------------------|---------------------|
| 0             | Input     | `input_handler`   | `input_handler.launch.py` |
| 1             | Process FSM | `process_handler`| `process_handler.launch.py` |
| 2             | Vision    | `camera_processor`| `camera_tracking.launch.py` |
| 3             | Motion    | `robot_controller`| `robot_controller.launch.py` |
| 4             | Scene     | `scene_handler`   | `scene_handler.launch.py` |

The Python launch file does the same but inside a single ROS launch hierarchy instead of TMUX panes.

---

### Build & Run

```bash
colcon build --packages-select bringup_robot
source install/setup.bash
```

**Option A – one terminal**

```bash
ros2 launch bringup_robot bringup_robot.launch.py
```

**Option B – multi‑pane TMUX**

```bash
chmod +x $(ros2 pkg prefix bringup_robot)/share/bringup_robot/scripts/bringup_tmux.sh
~/ws_mega_prosjekt/src/mekatronikk_mega_prosjekt/bringup_robot/scripts/bringup_tmux.sh
```

The script:

* Creates/clears a session named **ros_bringup**  
* Splits into five panes, cd’s into your workspace, sources `install/setup.bash`, and launches each subsystem.  
* Typing `Ctrl‑C` in any pane kills *all* panes thanks to the `trap` handler.

---

### Customising

* **Workspace path** – edit `WORKSPACE` in `bringup_tmux.sh` if your build dir is elsewhere.  
* **Pane layout** – adjust the `tmux split‑window` lines for a different grid.  
* **Subset bring‑up** – comment out an `IncludeLaunchDescription` (Python) or a `tmux send‑keys` block (shell) to exclude a subsystem.

---

### Troubleshooting

| Issue | Fix |
|-------|-----|
| “Package not found” | Make sure the workspace has been built and `setup.bash` sourced in each pane. |
| One pane exits instantly | Check its underlying launch file for syntax errors. |
---