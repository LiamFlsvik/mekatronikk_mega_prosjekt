// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from process_msgs:msg/CubeArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "process_msgs/msg/detail/cube_array__functions.h"
#include "process_msgs/msg/detail/cube_array__struct.hpp"
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

void CubeArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) process_msgs::msg::CubeArray(_init);
}

void CubeArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<process_msgs::msg::CubeArray *>(message_memory);
  typed_message->~CubeArray();
}

size_t size_function__CubeArray__cubes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<process_msgs::msg::Cube> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CubeArray__cubes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<process_msgs::msg::Cube> *>(untyped_member);
  return &member[index];
}

void * get_function__CubeArray__cubes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<process_msgs::msg::Cube> *>(untyped_member);
  return &member[index];
}

void fetch_function__CubeArray__cubes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const process_msgs::msg::Cube *>(
    get_const_function__CubeArray__cubes(untyped_member, index));
  auto & value = *reinterpret_cast<process_msgs::msg::Cube *>(untyped_value);
  value = item;
}

void assign_function__CubeArray__cubes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<process_msgs::msg::Cube *>(
    get_function__CubeArray__cubes(untyped_member, index));
  const auto & value = *reinterpret_cast<const process_msgs::msg::Cube *>(untyped_value);
  item = value;
}

void resize_function__CubeArray__cubes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<process_msgs::msg::Cube> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CubeArray_message_member_array[1] = {
  {
    "cubes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<process_msgs::msg::Cube>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs::msg::CubeArray, cubes),  // bytes offset in struct
    nullptr,  // default value
    size_function__CubeArray__cubes,  // size() function pointer
    get_const_function__CubeArray__cubes,  // get_const(index) function pointer
    get_function__CubeArray__cubes,  // get(index) function pointer
    fetch_function__CubeArray__cubes,  // fetch(index, &value) function pointer
    assign_function__CubeArray__cubes,  // assign(index, value) function pointer
    resize_function__CubeArray__cubes  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CubeArray_message_members = {
  "process_msgs::msg",  // message namespace
  "CubeArray",  // message name
  1,  // number of fields
  sizeof(process_msgs::msg::CubeArray),
  false,  // has_any_key_member_
  CubeArray_message_member_array,  // message members
  CubeArray_init_function,  // function to initialize message memory (memory has to be allocated)
  CubeArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CubeArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CubeArray_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__msg__CubeArray__get_type_hash,
  &process_msgs__msg__CubeArray__get_type_description,
  &process_msgs__msg__CubeArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace process_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::msg::CubeArray>()
{
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::CubeArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, msg, CubeArray)() {
  return &::process_msgs::msg::rosidl_typesupport_introspection_cpp::CubeArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
