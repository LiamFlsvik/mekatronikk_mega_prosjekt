// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:msg/Task.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK__BUILDER_HPP_
#define PROCESS_MSGS__MSG__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace msg
{

namespace builder
{

class Init_Task_command
{
public:
  Init_Task_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::process_msgs::msg::Task command(::process_msgs::msg::Task::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::msg::Task msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::msg::Task>()
{
  return process_msgs::msg::builder::Init_Task_command();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK__BUILDER_HPP_
