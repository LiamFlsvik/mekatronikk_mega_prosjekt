// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "process_msgs/msg/detail/task_feedback__functions.h"
#include "process_msgs/msg/detail/task_feedback__struct.hpp"
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

void TaskFeedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) process_msgs::msg::TaskFeedback(_init);
}

void TaskFeedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<process_msgs::msg::TaskFeedback *>(message_memory);
  typed_message->~TaskFeedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TaskFeedback_message_member_array[3] = {
  {
    "command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::TaskFeedback, command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::TaskFeedback, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::TaskFeedback, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TaskFeedback_message_members = {
  "process_msgs::msg",  // message namespace
  "TaskFeedback",  // message name
  3,  // number of fields
  sizeof(process_msgs::msg::TaskFeedback),
  false,  // has_any_key_member_
  TaskFeedback_message_member_array,  // message members
  TaskFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  TaskFeedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TaskFeedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TaskFeedback_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__msg__TaskFeedback__get_type_hash,
  &process_msgs__msg__TaskFeedback__get_type_description,
  &process_msgs__msg__TaskFeedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace process_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::msg::TaskFeedback>()
{
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::TaskFeedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, msg, TaskFeedback)() {
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::TaskFeedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
