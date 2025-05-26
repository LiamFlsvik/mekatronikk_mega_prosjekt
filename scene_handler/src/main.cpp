#include<rclcpp/rclcpp.hpp>
#include<scene_handler.hpp>
#include <rclcpp/executors/multi_threaded_executor.hpp> 
/*
int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<scene_handler>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}*/
int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<scene_handler>();
  rclcpp::executors::MultiThreadedExecutor exec(rclcpp::ExecutorOptions(), 2);
  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}