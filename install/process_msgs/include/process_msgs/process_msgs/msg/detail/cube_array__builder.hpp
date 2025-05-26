// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:msg/CubeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube_array.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__BUILDER_HPP_
#define PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/msg/detail/cube_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace msg
{

namespace builder
{

class Init_CubeArray_cubes
{
public:
  Init_CubeArray_cubes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::process_msgs::msg::CubeArray cubes(::process_msgs::msg::CubeArray::_cubes_type arg)
  {
    msg_.cubes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::msg::CubeArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::msg::CubeArray>()
{
  return process_msgs::msg::builder::Init_CubeArray_cubes();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__BUILDER_HPP_
