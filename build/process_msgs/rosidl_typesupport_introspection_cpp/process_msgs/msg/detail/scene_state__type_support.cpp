// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "process_msgs/msg/detail/scene_state__functions.h"
#include "process_msgs/msg/detail/scene_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace process_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SceneState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) process_msgs::msg::SceneState(_init);
}

void SceneState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<process_msgs::msg::SceneState *>(message_memory);
  typed_message->~SceneState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SceneState_message_member_array[3] = {
  {
    "cubes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<process_msgs::msg::CubeArray>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::SceneState, cubes),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "cubes_complete",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::SceneState, cubes_complete),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::SceneState, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SceneState_message_members = {
  "process_msgs::msg",  // message namespace
  "SceneState",  // message name
  3,  // number of fields
  sizeof(process_msgs::msg::SceneState),
  false,  // has_any_key_member_
  SceneState_message_member_array,  // message members
  SceneState_init_function,  // function to initialize message memory (memory has to be allocated)
  SceneState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SceneState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SceneState_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__msg__SceneState__get_type_hash,
  &process_msgs__msg__SceneState__get_type_description,
  &process_msgs__msg__SceneState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace process_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::msg::SceneState>()
{
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::SceneState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, msg, SceneState)() {
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::SceneState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
