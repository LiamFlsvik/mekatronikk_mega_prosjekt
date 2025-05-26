// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task_feedback.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__TRAITS_HPP_
#define PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/msg/detail/task_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace process_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TaskFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace process_msgs

namespace rosidl_generator_traits
{

[[deprecated("use process_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const process_msgs::msg::TaskFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::msg::TaskFeedback & msg)
{
  return process_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::msg::TaskFeedback>()
{
  return "process_msgs::msg::TaskFeedback";
}

template<>
inline const char * name<process_msgs::msg::TaskFeedback>()
{
  return "process_msgs/msg/TaskFeedback";
}

template<>
struct has_fixed_size<process_msgs::msg::TaskFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<process_msgs::msg::TaskFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<process_msgs::msg::TaskFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__TRAITS_HPP_
