#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <memory>
#include <vector>
#include <cmath>

using moveit::planning_interface::MoveGroupInterface;

class robot_controller_test_home: public rclcpp::Node, public std::enable_shared_from_this<robot_controller_test_home>
{

    robot_controller_test_home(): Node("robot_controller_test_home_node"), move_group_interface_(std::shared_ptr<rclcpp::Node>(std::static_pointer_cast<rclcpp::Node>(this->shared_from_this())), "ur_manipulator"){

    home_pose = []{
    geometry_msgs::msg::Pose msg;
    msg.orientation.w = 1.0;
    msg.position.x = 0.5;
    msg.position.y = -0.5;
    msg.position.z = 0.5;
    return msg;
    }();

    go_to_home_position();
    
    }




    void go_to_home_position()
    {
        move_group_interface.setPoseTarget(home_pose);
        
        move_group_interface.move();
        RCLCPP_INFO(this->get_logger(), "Moving to home position");
        move_group_interface.setStartStateToCurrentState();
        

    }

private:
geometry_msgs::msg::Pose home_pose;
 moveit::planning_interface::MoveGroupInterface move_group_interface;


};