cmake_minimum_required(VERSION 3.8)
project(process_msgs)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_runtime REQUIRED)

# Meldingsfiler
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Cube.msg"
  "msg/CubeArray.msg"
  "msg/KeyEvent.msg"
  "msg/SceneState.msg"
  "msg/Task.msg"
  "msg/TaskFeedback.msg"
  "srv/GetScene.srv"
  DEPENDENCIES geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
