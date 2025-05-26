// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE__TRAITS_HPP_
#define PROCESS_MSGS__MSG__DETAIL__CUBE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/msg/detail/cube__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace process_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Cube & msg,
  std::ostream & out)
{
  out << "{";
  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cube & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cube & msg, bool use_flow_style = false)
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
  const process_msgs::msg::Cube & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::msg::Cube & msg)
{
  return process_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::msg::Cube>()
{
  return "process_msgs::msg::Cube";
}

template<>
inline const char * name<process_msgs::msg::Cube>()
{
  return "process_msgs/msg/Cube";
}

template<>
struct has_fixed_size<process_msgs::msg::Cube>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<process_msgs::msg::Cube>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<process_msgs::msg::Cube>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE__TRAITS_HPP_
