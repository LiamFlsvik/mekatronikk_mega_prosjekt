from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    config_path = os.path.join(
        get_package_share_directory('camera_processor'),
        'resource',
        'usb_cam_parameters.yaml'
    )

    return LaunchDescription([
        Node(
            package='usb_cam',
            executable='usb_cam_node_exe',
            name='usb_cam',
            parameters=[config_path],
            output='screen'
        ),
        Node(
            package='camera_processor',
            executable='cube_tracker',
            name='cube_tracker',
            output='screen'
        )
    ])
