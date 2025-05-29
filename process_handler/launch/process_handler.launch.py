from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    robot_controller_node = Node(
        package='process_handler',
        executable='process_handler',
        name='process_handler',
        output='screen',
    )

    return LaunchDescription([
        robot_controller_node
    ])