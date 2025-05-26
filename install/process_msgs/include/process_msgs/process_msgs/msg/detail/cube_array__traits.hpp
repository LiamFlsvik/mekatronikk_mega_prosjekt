// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:msg/CubeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube_array.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__TRAITS_HPP_
#define PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/msg/detail/cube_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'cubes'
#include "process_msgs/msg/detail/cube__traits.hpp"

namespace process_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CubeArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: cubes
  {
    if (msg.cubes.size() == 0) {
      out << "cubes: []";
    } else {
      out << "cubes: [";
      size_t pending_items = msg.cubes.size();
      for (auto item : msg.cubes) {
        to_flow_style_yaml(item, out);
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
  const CubeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cubes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cubes.size() == 0) {
      out << "cubes: []\n";
    } else {
      out << "cubes:\n";
      for (auto item : msg.cubes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CubeArray & msg, bool use_flow_style = false)
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
  const process_msgs::msg::CubeArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::msg::CubeArray & msg)
{
  return process_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::msg::CubeArray>()
{
  return "process_msgs::msg::CubeArray";
}

template<>
inline const char * name<process_msgs::msg::CubeArray>()
{
  return "process_msgs/msg/CubeArray";
}

template<>
struct has_fixed_size<process_msgs::msg::CubeArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<process_msgs::msg::CubeArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<process_msgs::msg::CubeArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__TRAITS_HPP_
