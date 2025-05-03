#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <geometry_msgs/msg/pose.hpp>
using moveit::planning_interface::MoveGroupInterface;

class robot_controller_test_home: public rclcpp::Node
{
    public:
    robot_controller_test_home(): Node("robot_controller_test_home_node"),
    robot_model_loader_(std::make_shared<rclcpp::Node>(this->get_name()), "robot_description"),
    robot_model_(robot_model_loader_.getModel()),
    robot_state_(std::make_shared<moveit::core::RobotState>(robot_model_)),
    planning_group_("ur3"){
        
        go_to_home_position();

    }

   
    void go_to_home_position()
    {
        moveit::planning_interface::MoveGroupInterface move_group_interface(std::make_shared<rclcpp::Node>(this->get_name()), planning_group_);
        
        //get the current pose of the robot
        auto current_pose = move_group_interface.getCurrentPose();

        //Set the home position
        home_pose.position.x = 1;
        home_pose.position.y = 1;
        home_pose.position.z = 1;
        
        bool found_ik = robot_state_->setFromIK(joint_model_group_, home_pose);
        if (found_ik)
        {
            RCLCPP_INFO(this->get_logger(), "Inverse Kinematic solution found.");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Inverse Kinematic solution not found.");
        }

    }

private:
    robot_model_loader::RobotModelLoader robot_model_loader_;
    moveit::core::RobotModelPtr robot_model_;
    moveit::core::RobotStatePtr robot_state_;
    std::string planning_group_;
    const moveit::core::JointModelGroup* joint_model_group_;
    geometry_msgs::msg::Pose home_pose;


};