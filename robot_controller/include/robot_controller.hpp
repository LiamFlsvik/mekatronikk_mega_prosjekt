#include <chrono>
#include <thread>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit_msgs/msg/robot_trajectory.hpp>
#include <moveit/robot_model_loader/robot_model_loader.hpp>
#include <moveit/robot_state/robot_state.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>

using RobotModelLoader = robot_model_loader::RobotModelLoader;
using MoveGroupInterface = moveit::planning_interface::MoveGroupInterface;

class robot_controller : public rclcpp::Node
{
public:
  robot_controller()
  : Node("robot_controller_node"),
    robot_model_loader_(std::shared_ptr<rclcpp::Node>(this)),
    robot_model_(robot_model_loader_.getModel()),
    robot_state_(std::make_shared<moveit::core::RobotState>(robot_model_)),
    PLANNING_GROUP("ur_manipulator"),
    move_group_interface(std::shared_ptr<rclcpp::Node>(this), PLANNING_GROUP)
  {
    RCLCPP_INFO(get_logger(), "Robot Controller Node Started");
    joint_model_group_ = robot_model_->getJointModelGroup(PLANNING_GROUP);
    RCLCPP_INFO(get_logger(), "Move Group Interface Initialized");
    go_to_home_position();
    for (int i = 0; i < 5; ++i) {
      RCLCPP_INFO(get_logger(), "Scanning workplace %d", i);
      plan_with_constraints();
    }
  }

void plan_with_constraints(){
  
  joint_model_group_= move_group_interface.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
  robot_state_ = move_group_interface.getCurrentState();
  std::vector<double> joint_group_positions;
  robot_state_->copyJointGroupPositions(joint_model_group_, joint_group_positions);
  RCLCPP_INFO(get_logger(), "Planning frame: %s", move_group_interface.getPlanningFrame().c_str());
  RCLCPP_INFO(get_logger(), "End effector link: %s", move_group_interface.getEndEffectorLink().c_str());

// Constrains
  moveit_msgs::msg::OrientationConstraint ocm;
  ocm.link_name = "tool0";
  ocm.header.frame_id = "base_link";
  ocm.orientation.w = 1.0;
  ocm.absolute_x_axis_tolerance = 0.1;
  ocm.absolute_y_axis_tolerance = 0.1;
  ocm.absolute_z_axis_tolerance = 0.1;
  ocm.weight = 1.0;
  // Add the constraint to the path constraints
  moveit_msgs::msg::Constraints test_constraints;
  test_constraints.orientation_constraints.push_back(ocm);
  move_group_interface.setPathConstraints(test_constraints);

  moveit::core::RobotState start_state(*move_group_interface.getCurrentState());
  geometry_msgs::msg::Pose start_pose = move_group_interface.getCurrentPose().pose;
 
  start_state.setFromIK(joint_model_group_, start_pose);
  move_group_interface.setStartState(start_state);


  for (int i = 0; i < 3; i++) {
    geometry_msgs::msg::Pose target_pose;
    target_pose.position.x = this->poses[i][0].first;
    target_pose.position.y = this->poses[i][0].second;
    target_pose.position.z = 0.0;
    target_pose.orientation.w = 1.0;
    move_group_interface.setPoseTarget(target_pose);
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    auto success = move_group_interface.plan(plan);
    if (success) {
      RCLCPP_INFO(get_logger(), "Planning succeeded");
      move_group_interface.execute(plan);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    } else {
      RCLCPP_ERROR(get_logger(), "Planning failed");
    }

  }


  robot_state_ = move_group_interface.getCurrentState();
  

  go_to_home_position();
}

  void go_to_home_position()
  {
    std::vector<double> home_joints = {0.0, -1.57, 1.57, -1.57, -1.57, -3.14};
    move_group_interface.setJointValueTarget(home_joints);
    MoveGroupInterface::Plan plan;
    if (move_group_interface.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      move_group_interface.execute(plan);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    } else {
      RCLCPP_ERROR(get_logger(), "Home planning failed");
    }
  }

private:
  std::vector<std::vector<std::pair<double, double>>> poses = {{{0.1, 0.0}, {0.0, 0.1}}, {{-0.1, 0.0}, {0.0, -0.1}}};
  RobotModelLoader robot_model_loader_;
  moveit::core::RobotModelPtr robot_model_;
  moveit::core::RobotStatePtr robot_state_;
  const std::string PLANNING_GROUP;
  const moveit::core::JointModelGroup *joint_model_group_;
  MoveGroupInterface move_group_interface;
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  rclcpp::TimerBase::SharedPtr startup_timer_;
};

