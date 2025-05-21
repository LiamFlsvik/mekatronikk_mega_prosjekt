from launch import LaunchDescription
from moveit_configs_utils import MoveItConfigsBuilder

#The launch config 
#
#
launch_arguments = {
    "robot_ip": "xxx.yyy.zzz.www",
    "use_fake_hardware": "true",
    "gripper": "robotiq_2f_85",
    "dof": "7",
}

# Load the robot configuration
moveit_config = (
    MoveItConfigsBuilder(
        "gen3", package_name="kinova_gen3_7dof_robotiq_2f_85_moveit_config"
    )
    .robot_description(mappings=launch_arguments)
    .trajectory_execution(file_path="config/moveit_controllers.yaml")
    .planning_scene_monitor(
        publish_robot_description=True, publish_robot_description_semantic=True
    )
    .planning_pipelines(
        pipelines=["ompl", "stomp", "pilz_industrial_motion_planner"]
    )
    .to_moveit_configs()
)

def generate_launch_description():
    
    moveit_nodes = Node(

    )