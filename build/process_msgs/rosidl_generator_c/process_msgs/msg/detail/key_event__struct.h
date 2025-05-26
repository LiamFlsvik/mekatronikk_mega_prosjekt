// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/key_event.h"


#ifndef PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__STRUCT_H_
#define PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'active_keys'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/KeyEvent in the package process_msgs.
typedef struct process_msgs__msg__KeyEvent
{
  rosidl_runtime_c__String__Sequence active_keys;
} process_msgs__msg__KeyEvent;

// Struct for a sequence of process_msgs__msg__KeyEvent.
typedef struct process_msgs__msg__KeyEvent__Sequence
{
  process_msgs__msg__KeyEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__msg__KeyEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__STRUCT_H_
