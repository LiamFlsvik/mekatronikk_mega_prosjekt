// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from process_msgs:msg/Task.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task.h"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK__STRUCT_H_
#define PROCESS_MSGS__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Task in the package process_msgs.
typedef struct process_msgs__msg__Task
{
  /// MOVE_HOME | SCAN | POINT | ...
  rosidl_runtime_c__String command;
} process_msgs__msg__Task;

// Struct for a sequence of process_msgs__msg__Task.
typedef struct process_msgs__msg__Task__Sequence
{
  process_msgs__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK__STRUCT_H_
