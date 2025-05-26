// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task_feedback.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__BUILDER_HPP_
#define PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/msg/detail/task_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace msg
{

namespace builder
{

class Init_TaskFeedback_message
{
public:
  explicit Init_TaskFeedback_message(::process_msgs::msg::TaskFeedback & msg)
  : msg_(msg)
  {}
  ::process_msgs::msg::TaskFeedback message(::process_msgs::msg::TaskFeedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::msg::TaskFeedback msg_;
};

class Init_TaskFeedback_success
{
public:
  explicit Init_TaskFeedback_success(::process_msgs::msg::TaskFeedback & msg)
  : msg_(msg)
  {}
  Init_TaskFeedback_message success(::process_msgs::msg::TaskFeedback::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TaskFeedback_message(msg_);
  }

private:
  ::process_msgs::msg::TaskFeedback msg_;
};

class Init_TaskFeedback_command
{
public:
  Init_TaskFeedback_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskFeedback_success command(::process_msgs::msg::TaskFeedback::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_TaskFeedback_success(msg_);
  }

private:
  ::process_msgs::msg::TaskFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::msg::TaskFeedback>()
{
  return process_msgs::msg::builder::Init_TaskFeedback_command();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__BUILDER_HPP_
