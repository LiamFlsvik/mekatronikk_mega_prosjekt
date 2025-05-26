# Launch file for cube_tracker and launching USB camera
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # USB Camera Node
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='usb_cam',
            output='screen',
            parameters=[{
                'video_device': '/dev/video0',  # Camera device path
                'framerate': 30.0,
                'image_width': 640,
                'image_height': 480,
                'pixel_format': 'yuyv'
            }],
            remappings=[
                ('/image_raw', '/camera/image_raw')
    ]
        ),

        # Cube Tracker Node
        Node(
            package='camera_processor',
            executable='cube_tracker',
            name='cube_tracker',
            output='screen'
        )
    ])
