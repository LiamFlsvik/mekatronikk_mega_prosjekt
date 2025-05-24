from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # USB kamera-node (med /dev/video2)
        Node(
        package='usb_cam',
        executable='usb_cam_node_exe',
        name='usb_cam',
        parameters=[{
            'video_device': '/dev/video2',
            'framerate': 30.0,
            'image_width': 640,
            'image_height': 480
        }]
),

        # Cube-tracker-node
        Node(
            package='camera_processor',
            executable='cube_tracker',
            name='cube_tracker',
            output='screen'
        )
    ])
