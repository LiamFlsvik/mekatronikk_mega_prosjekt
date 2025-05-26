// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice
#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define PROCESS_MSGS__MSG__DETAIL__CUBE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "process_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "process_msgs/msg/detail/cube__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
bool cdr_serialize_process_msgs__msg__Cube(
  const process_msgs__msg__Cube * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
bool cdr_deserialize_process_msgs__msg__Cube(
  eprosima::fastcdr::Cdr &,
  process_msgs__msg__Cube * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
size_t get_serialized_size_process_msgs__msg__Cube(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
size_t max_serialized_size_process_msgs__msg__Cube(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
bool cdr_serialize_key_process_msgs__msg__Cube(
  const process_msgs__msg__Cube * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
size_t get_serialized_size_key_process_msgs__msg__Cube(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
size_t max_serialized_size_key_process_msgs__msg__Cube(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_process_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, process_msgs, msg, Cube)();

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
