# **process_msgs**

`process_msgs` defines the custom ROS 2 messages and the single service used by input, vision, control, and the task‑level state machine.

---

## Messages

| Message | Purpose | Fields |
|---------|---------|--------|
| **`Cube.msg`** | Single cube pose in robot base frame | `string color` – one of **red / yellow / blue / green**<br>`geometry_msgs/Point position` – metres in **base_link**<br>`float32 angle` – yaw radians |
| **`CubeArray.msg`** | Collection of cubes | `Cube[] cubes` |
| **`KeyEvent.msg`** | Debounced keyboard state | `string[] active_keys` – keys currently held |
| **`SceneState.msg`** | Snapshot of the vision scene | `CubeArray cubes` – latest cube list<br>`bool cubes_complete` – **true** when all colours present<br>`builtin_interfaces/Time stamp` – wall clock |
| **`Task.msg`** | High‑level command from operator/state machine | `string command` – `MOVE_HOME`, `SCAN`, `POINT`, … |
| **`TaskFeedback.msg`** | Execution result from robot | `string command` – echoes the request<br>`bool success` – OK/Fail<br>`string message` – optional details |

---

## Service

| Service | Request | Response | Use case |
|---------|---------|----------|----------|
| **`GetScene.srv`** | *(empty)* | `SceneState scene` | One‑shot pull of the latest vision scene (e.g. planning step) |

---

## Build & Use

```bash
colcon build --packages-select process_msgs
source install/setup.bash
```

After building, import the interfaces in C++:

```cpp
#include "process_msgs/msg/cube.hpp"
#include "process_msgs/srv/get_scene.hpp"
```

…or in Python:

```python
from process_msgs.msg import Task, TaskFeedback
```

---
