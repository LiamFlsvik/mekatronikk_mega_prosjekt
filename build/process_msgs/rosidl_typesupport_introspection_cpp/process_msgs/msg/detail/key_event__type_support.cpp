// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "process_msgs/msg/detail/key_event__functions.h"
#include "process_msgs/msg/detail/key_event__struct.hpp"
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

void KeyEvent_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) process_msgs::msg::KeyEvent(_init);
}

void KeyEvent_fini_function(void * message_memory)
{
  auto typed_message = static_cast<process_msgs::msg::KeyEvent *>(message_memory);
  typed_message->~KeyEvent();
}

size_t size_function__KeyEvent__active_keys(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__KeyEvent__active_keys(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__KeyEvent__active_keys(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__KeyEvent__active_keys(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__KeyEvent__active_keys(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__KeyEvent__active_keys(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__KeyEvent__active_keys(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__KeyEvent__active_keys(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember KeyEvent_message_member_array[1] = {
  {
    "active_keys",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::KeyEvent, active_keys),  // bytes offset in struct
    nullptr,  // default value
    size_function__KeyEvent__active_keys,  // size() function pointer
    get_const_function__KeyEvent__active_keys,  // get_const(index) function pointer
    get_function__KeyEvent__active_keys,  // get(index) function pointer
    fetch_function__KeyEvent__active_keys,  // fetch(index, &value) function pointer
    assign_function__KeyEvent__active_keys,  // assign(index, value) function pointer
    resize_function__KeyEvent__active_keys  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers KeyEvent_message_members = {
  "process_msgs::msg",  // message namespace
  "KeyEvent",  // message name
  1,  // number of fields
  sizeof(process_msgs::msg::KeyEvent),
  false,  // has_any_key_member_
  KeyEvent_message_member_array,  // message members
  KeyEvent_init_function,  // function to initialize message memory (memory has to be allocated)
  KeyEvent_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t KeyEvent_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &KeyEvent_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__msg__KeyEvent__get_type_hash,
  &process_msgs__msg__KeyEvent__get_type_description,
  &process_msgs__msg__KeyEvent__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace process_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::msg::KeyEvent>()
{
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::KeyEvent_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, msg, KeyEvent)() {
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::KeyEvent_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
