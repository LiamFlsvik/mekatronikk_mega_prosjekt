#include <rclcpp/rclcpp.hpp>
#include "robot_controller_test_home.hpp"


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    
    auto home_node = std::make_shared<robot_controller_test_home>();
    home_node->go_to_home_position(); 

    rclcpp::spin(home_node);
    rclcpp::shutdown();
    return 0;
}