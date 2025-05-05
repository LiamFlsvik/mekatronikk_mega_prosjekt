

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/robot_model_loader/robot_model_loader.hpp>
#include <moveit/robot_state/robot_state.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit/planning_interface/planning_interface.hpp>
//#include <your_action_package/action/move_robot.hpp>

// TODO: Action client for going to home position?

class robot_controller: public rclcpp::Node
{
    public:
    robot_controller(): Node("robot_controller_node"),
    robot_model_loader_(std::make_shared<rclcpp::Node>(this->get_name()), "robot_description"),
    robot_model_(robot_model_loader_.getModel()),
    robot_state_(std::make_shared<moveit::core::RobotState>(robot_model_)), PLANNING_GROUP("ur_manipulator")
    { 
      RCLCPP_INFO(this->get_logger(), "Robot Controller Node Started");

      joint_model_group_ = robot_model_->getJointModelGroup(PLANNING_GROUP);

      move_group_interface = std::make_shared<moveit::planning_interface::MoveGroupInterface>(std::shared_ptr<rclcpp::Node>(this), PLANNING_GROUP);
      RCLCPP_INFO(this->get_logger(), "Move Group Interface Initialized");
      
      // Initialize the home pose
      go_to_home_position();

    }

    void go_to_home_position(){
        // Set the home position
        std::vector<double> home_joint_values = {0.0, -1.57,  1.57, -1.57,  -1.57,  -3.14};


        move_group_interface->setJointValueTarget(home_joint_values);

        moveit::planning_interface::MoveGroupInterface::Plan plan;

        bool success = (move_group_interface->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if(success){
          RCLCPP_INFO(this->get_logger(), "Planning to home position succeeded");
          move_group_interface->execute(plan);
          RCLCPP_INFO(this->get_logger(), "Executing home position succeeded");
        }
        else{
          RCLCPP_ERROR(this->get_logger(), "Failed to plan to home position"); 
        }

    }

private:
  robot_model_loader::RobotModelLoader robot_model_loader_;
  moveit::core::RobotModelPtr robot_model_;
  moveit::core::RobotStatePtr robot_state_;
  const std::string PLANNING_GROUP;
  const moveit::core::JointModelGroup* joint_model_group_;
  geometry_msgs::msg::Pose home_pose;
  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_interface;

  // Actions
  
  //rclcpp_action::Server<your_action_package::action::MoveRobot>::SharedPtr move_to_pos_action_server_;

};