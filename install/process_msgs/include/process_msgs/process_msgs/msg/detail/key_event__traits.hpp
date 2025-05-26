// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/key_event.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__TRAITS_HPP_
#define PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/msg/detail/key_event__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace process_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const KeyEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: active_keys
  {
    if (msg.active_keys.size() == 0) {
      out << "active_keys: []";
    } else {
      out << "active_keys: [";
      size_t pending_items = msg.active_keys.size();
      for (auto item : msg.active_keys) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KeyEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: active_keys
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.active_keys.size() == 0) {
      out << "active_keys: []\n";
    } else {
      out << "active_keys:\n";
      for (auto item : msg.active_keys) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KeyEvent & msg, bool use_flow_style = false)
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
  const process_msgs::msg::KeyEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::msg::KeyEvent & msg)
{
  return process_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::msg::KeyEvent>()
{
  return "process_msgs::msg::KeyEvent";
}

template<>
inline const char * name<process_msgs::msg::KeyEvent>()
{
  return "process_msgs/msg/KeyEvent";
}

template<>
struct has_fixed_size<process_msgs::msg::KeyEvent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<process_msgs::msg::KeyEvent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<process_msgs::msg::KeyEvent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__TRAITS_HPP_
