cd ~/ros2_ws/MegaProsjekt
colcon build --packages-select launch_files
source install/setup.bash
ros2 launch launch_files usb_cam_launch.py

#Kalibrering av Farger
nano ~/ros2_ws/mega_prosjekt/src/mekatronikk_mega_prosjekt/camera_processor/resource/calibrate_color.py 
python3 src/mekatronikk_mega_prosjekt/camera_processor/resource/calibrate_color.py

#Finn riktig kamera ting:
v4l2-ctl --list-devices


SCENE: 45cm (L) x33,5cm x 38cm (H)


#Term 1 (gammel):
cd ~/ros2_ws/MegaProsjekt
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/.venv/bin/activate
colcon build --packages-select launch_files
source install/setup.bash
ros2 launch launch_files usb_cam_launch.py


#Term 2:
cd ~/ros2_ws/mega_prosjekt
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/.venv/bin/activate
colcon build --packages-select camera_processor
source install/setup.bash
ros2 run camera_processor cube_tracker


#Kalibrering av kamera:
ros2 run camera_calibration cameracalibrator --size 9x7 --square 0.02 image:=/camera/image_raw camera:=/camera --no-service-check

#Oppdatering av Kalibrert data:
mkdir -p ~/camera_calibration_data
tar -xzf /tmp/calibrationdata.tar.gz -C ~/camera_calibration_data
nano ~/camera_calibration_data/ost.yaml #Posisjons data




# For laste ned nødvendige verktøy
cd ~/ros2_ws
python3.12 -m venv .venv
source ~/ros2_ws/.venv/bin/activate

pip install "cvzone" "opencv-python" "numpy<2" "pyyaml"

# Kalibrering av Farger:
nano ~/ros2_ws/mega_prosjekt/src/mekatronikk_mega_prosjekt/resource/calibrate_color.py #Fillokasjon for å endre på
python3 calibrate_color.py

# Bygg og kjør cube_tracker:
cd ~/ros2_ws/mega_prosjekt
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/.venv/bin/activate
colcon build --packages-select camera_processor
source install/setup.bash
ros2 run camera_processor cube_tracker

# Bygg og kjør gammel usb_cam launch fil:
cd ~/ros2_ws/MegaProsjekt
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/.venv/bin/activate
colcon build --packages-select launch_files
source install/setup.bash
ros2 launch launch_files usb_cam_launch.py