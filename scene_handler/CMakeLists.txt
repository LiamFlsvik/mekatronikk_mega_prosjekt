cmake_minimum_required(VERSION 3.10)
project(scene_handler)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_visual_tools REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(Eigen3 3.3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(process_msgs REQUIRED)
find_package(robot_state_publisher REQUIRED)
include_directories(include)

add_executable(scene_handler_node src/main.cpp include/scene_handler.hpp)

ament_target_dependencies(scene_handler_node
  rclcpp
  moveit_ros_planning_interface
  moveit_msgs
  geometry_msgs
  shape_msgs
  process_msgs 
  robot_state_publisher
)

install(TARGETS scene_handler_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

target_link_libraries(scene_handler_node
  ${OpenCV_LIBS}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
