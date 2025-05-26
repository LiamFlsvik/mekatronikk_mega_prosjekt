import rclpy
from rclpy.node import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node as LaunchNode
import subprocess

def main():
    rclpy.init()

    # Start kamera-node manuelt med subprocess
    subprocess.Popen([
        'ros2', 'run', 'usb_cam2', 'usb_cam_node_exe',
        '--ros-args',
        '-p', 'video_device:=/dev/video2',
        '-p', 'framerate:=30.0',
        '-p', 'image_width:=640',
        '-p', 'image_height:=480',
        '-p', 'camera_name:=usb_cam2'
    ])

    print("USB CAM started... (Ctrl+C to stop)")

    try:
        rclpy.spin(rclpy.create_node('camera_begin_dummy'))
    except KeyboardInterrupt:
        print("\nShutting down...")
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
