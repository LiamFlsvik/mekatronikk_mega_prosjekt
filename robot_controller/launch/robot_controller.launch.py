from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    param_file = os.path.join(
        get_package_share_directory('robot_controller'),
        'config',
        'parameters.yaml'
    )   

    robot_controller_node = Node(
        package='robot_controller',
        executable='robot_controller_node',
        name='robot_controller_node',
        output='screen',
        parameters=[param_file]
    )

    return LaunchDescription([
        robot_controller_node
    ])