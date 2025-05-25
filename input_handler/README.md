# **Input Handler**

`keyboard_input_handler` captures keyboard events and publishes the set at 20 Hz.
It listens for **W**, **Space**, and **Enter**, and publishes them them as `process_msgs/KeyEvent` message on `/active_keys`.

---

### Functionality

- **Key Press**  
  When **W**, **Space**, or **Enter** is pressed, that key is added to the active set.
- **Key Release**  
  When any of those keys is released, it’s removed from the active set.
- **Periodic Publish**  
  Every 50 ms, the handler publishes a `KeyEvent` containing `active_keys`, a list of currently held keys  

---

### Interfaces

| Direction      | Topic           | Type                     | Purpose                     |
|----------------|-----------------|--------------------------|-----------------------------|
| **Publishes**  | `/active_keys`  | `process_msgs/KeyEvent`  | Current set of pressed keys |


---

### Build & Run Instructions

```bash
colcon build --packages-select input_handler
source install/setup.bash
```

```bash
ros2 run keyboard_input_handler keyboard_input_handler
```

---

### Troubleshooting

| Symptom                             | Remedy                                                                                 |
|-------------------------------------|----------------------------------------------------------------------------------------|
| No `/active_keys` messages appear   | • Ensure terminal window has focus (listener needs keyboard focus).<br>• Verify `valid_keys` includes the key you’re testing. |
| `ModuleNotFoundError: process_msgs` | Run `colcon build --packages-select keyboard_input_handler`, then `source install/setup.bash`. |
| Handler seems unresponsive          | Check that `pynput` is installed (`pip install pynput`) and that your OS allows global keyboard hooks. |
| Very high CPU usage                 | Increase the timer period in `create_timer(…)`, e.g. from `0.05` to `0.1` seconds.      |

---
