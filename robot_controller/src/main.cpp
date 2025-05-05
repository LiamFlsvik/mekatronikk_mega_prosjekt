#include <rclcpp/rclcpp.hpp>
#include <robot_controller.hpp>



int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<robot_controller>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}