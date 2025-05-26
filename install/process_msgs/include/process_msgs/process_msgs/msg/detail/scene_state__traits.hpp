// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/scene_state.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__TRAITS_HPP_
#define PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/msg/detail/scene_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'cubes'
#include "process_msgs/msg/detail/cube_array__traits.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace process_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SceneState & msg,
  std::ostream & out)
{
  out << "{";
  // member: cubes
  {
    out << "cubes: ";
    to_flow_style_yaml(msg.cubes, out);
    out << ", ";
  }

  // member: cubes_complete
  {
    out << "cubes_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.cubes_complete, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SceneState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cubes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cubes:\n";
    to_block_style_yaml(msg.cubes, out, indentation + 2);
  }

  // member: cubes_complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cubes_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.cubes_complete, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SceneState & msg, bool use_flow_style = false)
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
  const process_msgs::msg::SceneState & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::msg::SceneState & msg)
{
  return process_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::msg::SceneState>()
{
  return "process_msgs::msg::SceneState";
}

template<>
inline const char * name<process_msgs::msg::SceneState>()
{
  return "process_msgs/msg/SceneState";
}

template<>
struct has_fixed_size<process_msgs::msg::SceneState>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<process_msgs::msg::CubeArray>::value> {};

template<>
struct has_bounded_size<process_msgs::msg::SceneState>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<process_msgs::msg::CubeArray>::value> {};

template<>
struct is_message<process_msgs::msg::SceneState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__TRAITS_HPP_
