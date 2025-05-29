from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    input_handler_launch = os.path.join(
        get_package_share_directory('input_handler'), 'launch', 'input_handler.launch.py'
    )

    process_handler_launch = os.path.join(
        get_package_share_directory('process_handler'), 'launch', 'process_handler.launch.py'
    )

    camera_tracking_launch = os.path.join(
        get_package_share_directory('camera_processor'), 'launch', 'camera_tracking.launch.py'
    )

    robot_controller_launch = os.path.join(
        get_package_share_directory('robot_controller'), 'launch', 'robot_controller.launch.py'
    )

    scene_handler_launch = os.path.join(
        get_package_share_directory('scene_handler'), 'launch', 'scene_handler.launch.py'
    )

    return LaunchDescription([
        IncludeLaunchDescription(PythonLaunchDescriptionSource(input_handler_launch)),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(process_handler_launch)),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(camera_tracking_launch)),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(robot_controller_launch)),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(scene_handler_launch)),
    ])
