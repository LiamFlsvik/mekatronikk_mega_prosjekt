#include <rclcpp/rclcpp.hpp>
#include <robot_controller.hpp>



int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<robot_controller>();
  rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}