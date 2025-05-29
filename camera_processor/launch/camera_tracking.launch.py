from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config_file = os.path.join(
        get_package_share_directory('camera_processor'),
        'config',
        'usb_cam_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='usb_cam',
            output='screen',
            parameters=[config_file],
            remappings=[
                ('/image_raw', '/camera/image_raw')
            ]
        ),

        Node(
            package='camera_processor',
            executable='cube_tracker',
            name='cube_tracker',
            output='screen'
        )
    ])
