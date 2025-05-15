#include<rclcpp/rclcpp.hpp>
#include<scene_handler.hpp>


int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<scene_handler>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}