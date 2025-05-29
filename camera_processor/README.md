# **camera_processor**

`camera_processor` contains **Cube Tracker**, a vision node that finds the four coloured cubes in each camera frame and publishes their pixel‑space pose as a `CubeArray`.

The node had multiple HSV ranges (tuned for several lighting profiles), picks the largest contour of each colour, computes the center coordinates and rotation, and publishes an array of `process_msgs/Cube` messages at around 40 Hz.

---

### Functionality

1. **Image intake** – subscribes to `/camera/image_raw` (`sensor_msgs/Image`) and converts to OpenCV BGR.  
2. **Colour masking** – for every colour (*red, blue, yellow, green*) it iterates through a list of HSV profiles until at least one mask yields a contour.  
3. **Pose extraction** – from the biggest contour it computes:
   * centre pixel `(cx, cy)`  
   * rotation angle (deg → rad) using `cv2.minAreaRect`.  
4. **Publishing** – pushes the whole set as a single `CubeArray` on `/cubes/detections`.  
5. **Diagnostics** – draws bounding boxes, writes a snapshot to `resource/cube_snapshot.png`, and shows a live “Cube Tracking” window for quick tuning.

Execution is throttled to **40 fps** and delayed **2 s** after node start to let the camera settle.

---

### Interfaces

| Direction   | Topic               | Type                | Purpose                          |
|-------------|---------------------|---------------------|----------------------------------|
| **Subscribes** | `/camera/image_raw` | `sensor_msgs/Image` | Raw camera frames (USB cam)      |
| **Publishes**  | `/cubes/detections` | `process_msgs/CubeArray` | Pixel positions and angles of cubes |

---

### HSV Profiles

The tracker carries several built‑in HSV tables so you can switch lighting
```python
hsv_profiles = [
    {   # Lights off profile
        'name': 'lights_off',
        'ranges': {
            'red':    {'hmin':131,'smin':64,'vmin':67,'hmax':179,'smax':255,'vmax':255},
            'blue':   {'hmin':85 ,'smin':95,'vmin':0,'hmax':159,'smax':255,'vmax':255},
            'yellow': {'hmin':15 ,'smin':98,'vmin':0,'hmax':50 ,'smax':255,'vmax':255},
            'green':  {'hmin':55 ,'smin':81,'vmin':0,'hmax':94 ,'smax':255,'vmax':255},
        }
    },
    ...
]
```

Use the on‑screen window together with `rqt_reconfigure` to fine‑tune new ranges.

---

### Build & Run

```bash
colcon build --packages-select camera_processor
source install/setup.bash
```

```bash
ros2 run camera_processor cube_tracker
```

Or start tracker using Launch file:

```bash
ros2 launch camera_processor camera_tracking.launch.py
```

---

### Troubleshooting

| Symptom | Possible Fix |
|---------|--------------|
| No window appears | Make sure you have a desktop session and OpenCV built with GUI support (`sudo apt install cvzone`). |
| Cube colours bleed together | Tighten the HSV `smin`/`vmin`. |
| Contours flicker | Enable a single lighting profile that best matches your environment to avoid profile hopping. |
| `cv_bridge` errors | Re‑build the workspace and source the correct `setup.bash`. |

---
