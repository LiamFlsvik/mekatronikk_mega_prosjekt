// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE__BUILDER_HPP_
#define PROCESS_MSGS__MSG__DETAIL__CUBE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/msg/detail/cube__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace msg
{

namespace builder
{

class Init_Cube_angle
{
public:
  explicit Init_Cube_angle(::process_msgs::msg::Cube & msg)
  : msg_(msg)
  {}
  ::process_msgs::msg::Cube angle(::process_msgs::msg::Cube::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::msg::Cube msg_;
};

class Init_Cube_position
{
public:
  explicit Init_Cube_position(::process_msgs::msg::Cube & msg)
  : msg_(msg)
  {}
  Init_Cube_angle position(::process_msgs::msg::Cube::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Cube_angle(msg_);
  }

private:
  ::process_msgs::msg::Cube msg_;
};

class Init_Cube_color
{
public:
  Init_Cube_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cube_position color(::process_msgs::msg::Cube::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_Cube_position(msg_);
  }

private:
  ::process_msgs::msg::Cube msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::msg::Cube>()
{
  return process_msgs::msg::builder::Init_Cube_color();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE__BUILDER_HPP_
