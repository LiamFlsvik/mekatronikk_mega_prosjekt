// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:msg/Task.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK__TRAITS_HPP_
#define PROCESS_MSGS__MSG__DETAIL__TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace process_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Task & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task & msg, bool use_flow_style = false)
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
  const process_msgs::msg::Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::msg::Task & msg)
{
  return process_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::msg::Task>()
{
  return "process_msgs::msg::Task";
}

template<>
inline const char * name<process_msgs::msg::Task>()
{
  return "process_msgs/msg/Task";
}

template<>
struct has_fixed_size<process_msgs::msg::Task>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<process_msgs::msg::Task>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<process_msgs::msg::Task>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK__TRAITS_HPP_
