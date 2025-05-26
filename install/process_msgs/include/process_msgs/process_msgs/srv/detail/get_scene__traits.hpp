// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/srv/get_scene.hpp"


#ifndef PROCESS_MSGS__SRV__DETAIL__GET_SCENE__TRAITS_HPP_
#define PROCESS_MSGS__SRV__DETAIL__GET_SCENE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "process_msgs/srv/detail/get_scene__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace process_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetScene_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetScene_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetScene_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_generator_traits
{

[[deprecated("use process_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const process_msgs::srv::GetScene_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::srv::GetScene_Request & msg)
{
  return process_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::srv::GetScene_Request>()
{
  return "process_msgs::srv::GetScene_Request";
}

template<>
inline const char * name<process_msgs::srv::GetScene_Request>()
{
  return "process_msgs/srv/GetScene_Request";
}

template<>
struct has_fixed_size<process_msgs::srv::GetScene_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<process_msgs::srv::GetScene_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<process_msgs::srv::GetScene_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'scene'
#include "process_msgs/msg/detail/scene_state__traits.hpp"

namespace process_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetScene_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: scene
  {
    out << "scene: ";
    to_flow_style_yaml(msg.scene, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetScene_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: scene
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scene:\n";
    to_block_style_yaml(msg.scene, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetScene_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_generator_traits
{

[[deprecated("use process_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const process_msgs::srv::GetScene_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::srv::GetScene_Response & msg)
{
  return process_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::srv::GetScene_Response>()
{
  return "process_msgs::srv::GetScene_Response";
}

template<>
inline const char * name<process_msgs::srv::GetScene_Response>()
{
  return "process_msgs/srv/GetScene_Response";
}

template<>
struct has_fixed_size<process_msgs::srv::GetScene_Response>
  : std::integral_constant<bool, has_fixed_size<process_msgs::msg::SceneState>::value> {};

template<>
struct has_bounded_size<process_msgs::srv::GetScene_Response>
  : std::integral_constant<bool, has_bounded_size<process_msgs::msg::SceneState>::value> {};

template<>
struct is_message<process_msgs::srv::GetScene_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace process_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetScene_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
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
  const GetScene_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetScene_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_generator_traits
{

[[deprecated("use process_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const process_msgs::srv::GetScene_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  process_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use process_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const process_msgs::srv::GetScene_Event & msg)
{
  return process_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<process_msgs::srv::GetScene_Event>()
{
  return "process_msgs::srv::GetScene_Event";
}

template<>
inline const char * name<process_msgs::srv::GetScene_Event>()
{
  return "process_msgs/srv/GetScene_Event";
}

template<>
struct has_fixed_size<process_msgs::srv::GetScene_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<process_msgs::srv::GetScene_Event>
  : std::integral_constant<bool, has_bounded_size<process_msgs::srv::GetScene_Request>::value && has_bounded_size<process_msgs::srv::GetScene_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<process_msgs::srv::GetScene_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<process_msgs::srv::GetScene>()
{
  return "process_msgs::srv::GetScene";
}

template<>
inline const char * name<process_msgs::srv::GetScene>()
{
  return "process_msgs/srv/GetScene";
}

template<>
struct has_fixed_size<process_msgs::srv::GetScene>
  : std::integral_constant<
    bool,
    has_fixed_size<process_msgs::srv::GetScene_Request>::value &&
    has_fixed_size<process_msgs::srv::GetScene_Response>::value
  >
{
};

template<>
struct has_bounded_size<process_msgs::srv::GetScene>
  : std::integral_constant<
    bool,
    has_bounded_size<process_msgs::srv::GetScene_Request>::value &&
    has_bounded_size<process_msgs::srv::GetScene_Response>::value
  >
{
};

template<>
struct is_service<process_msgs::srv::GetScene>
  : std::true_type
{
};

template<>
struct is_service_request<process_msgs::srv::GetScene_Request>
  : std::true_type
{
};

template<>
struct is_service_response<process_msgs::srv::GetScene_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PROCESS_MSGS__SRV__DETAIL__GET_SCENE__TRAITS_HPP_
