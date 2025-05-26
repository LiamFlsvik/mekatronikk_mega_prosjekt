# **Camera Processor**

Is the node that takes the image from `USB_CAM` and uses `CUBETRACKER` to track the different colored cubes (Red, Blue, Green and Yellow). This system uses ROS 2 and OpenCV to identify the cubes and publishes their position, color and rotation into `CubeArray`
---

## Functions

* Tracks the colored cubes given their HSV parameters
* Visualises the cubes with a rotated bounding box
* Publishes position, color, rotation and size
* Lets you calibrate both the camera matrix and color tracker


---

## Dependencies

### 1. Clone and install USB_CAM driver:

```bash
cd ~/ros2_ws/src
git clone https://github.com/ros-drivers/usb_cam.git
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
colcon build --packages-select usb_cam
```

---

### 2. Create a virtual environment and install Python-dependencies

```bash
cd ~/ros2_ws
python3.12 -m venv .venv
source ~/ros2_ws/.venv/bin/activate
pip install "cvzone" "opencv-python" "numpy<2" "pyyaml" "em" "catkin_pkg" "lark"
```

---

### 3. Calibration of camera

Run the following command and calibrate the camera with a chess board pattern A4 paper.
LINK to a more in depth calibration tutorial: https://docs.ros.org/en/ros2_packages/rolling/api/camera_calibration/doc/tutorial_mono.html

```bash
ros2 run camera_calibration cameracalibrator --size 8x6 --square 0.025 image:=/camera/image_raw camera:=/camera --no-service-check
```

> The saved calibration data will then have to be moved to `/resource/ost.yaml`.

---

### 4. Calibration of HSV-values:

Use the following line of commands down below. 

```bash
cd ~/ros2_ws/mega_prosjekt/src/mekatronikk_mega_prosjekt/camera_processor/resource
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/.venv/bin/activate
python3 calibrate_color.py
```

Drag the HSV parameters untill you only see the desired cube. Press CTRL+C. And copy paste the HSV value from the terminal into the desired color range like below:

```bash
self.color_ranges = { # Define HSV color ranges for different cubes (Semi controlled lighting)
            'red':   {'hmin': 35, 'smin': 4, 'vmin': 255, 'hmax': 179, 'smax': 241, 'vmax': 255},
            'blue':  {'hmin': 100, 'smin': 102, 'vmin': 90, 'hmax': 114, 'smax': 224, 'vmax': 255},
            'yellow': {'hmin': 14, 'smin': 55, 'vmin': 164, 'hmax': 42, 'smax': 194, 'vmax': 255},
            'green': {'hmin': 37, 'smin': 82, 'vmin': 86, 'hmax': 82, 'smax': 157, 'vmax': 170},
        }
```

---

### Build and run


## Find the correct camera:
```bash
v4l2-ctl --list-devices
```
> Then update `/dev/videoX` to your desired camera in `XXXX`


## Run `cube_tracker` directly
```bash
cd ~/ros2_ws/mega_prosjekt
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/.venv/bin/activate
colcon build --packages-select camera_processor process_msgs
source install/setup.bash
ros2 run camera_processor cube_tracker
```



---

## Published messages

| Topic                   | Type                     | Beskrivelse                                                  |
| ----------------------- | ------------------------ | ------------------------------------------------------------ |
| `/red_cube_position`    | `geometry_msgs/Point`    | Position, area and rotation for red cube                     |
| `/blue_cube_position`   | `geometry_msgs/Point`    | Position, area and rotation for blue cube                    |
| `/yellow_cube_position` | `geometry_msgs/Point`    | Position, area and rotation for yellow cube                  |
| `/green_cube_position`  | `geometry_msgs/Point`    | Position, area and rotation for green cube                   |
| `/cubes/detections`     | `process_msgs/CubeArray` | Full data per cube (position, color, rotation, size)         |

---

cd ~/ros2_ws
colcon build --packages-select camera_processor
source install/setup.bash
ros2 launch camera_processor camera_tracking.launch.py


colcon build --packages-select camera_processor
source install/setup.bash
ros2 launch camera_processor camera_tracking.launch.py

colcon build --packages-select process_msgs
source install/setup.bash
ros2 topic echo /cubes/detections