from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    robot_controller_node = Node(
        package='input_handler',
        executable='input_handler',
        name='input_handler',
        output='screen',
        prefix='xterm -e'
    )

    return LaunchDescription([
        robot_controller_node
    ])
