from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    param_file = os.path.join(
        get_package_share_directory('scene_handler'),
        'config',
        'parameters.yaml'
    )   

    scene_handler_node = Node(
        package='scene_handler',
        executable='scene_handler_node',
        name='scene_handler_node',
        output='screen',
        parameters=[param_file]
    )

    return LaunchDescription([
        scene_handler_node
    ])





