// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/key_event.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__BUILDER_HPP_
#define PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/msg/detail/key_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace msg
{

namespace builder
{

class Init_KeyEvent_active_keys
{
public:
  Init_KeyEvent_active_keys()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::process_msgs::msg::KeyEvent active_keys(::process_msgs::msg::KeyEvent::_active_keys_type arg)
  {
    msg_.active_keys = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::msg::KeyEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::msg::KeyEvent>()
{
  return process_msgs::msg::builder::Init_KeyEvent_active_keys();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__BUILDER_HPP_
