// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task_feedback.h"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__STRUCT_H_
#define PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__STRUCT_H_

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
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TaskFeedback in the package process_msgs.
typedef struct process_msgs__msg__TaskFeedback
{
  /// echoes the command just executed
  rosidl_runtime_c__String command;
  /// true = finished OK
  bool success;
  /// optional human-readable info
  rosidl_runtime_c__String message;
} process_msgs__msg__TaskFeedback;

// Struct for a sequence of process_msgs__msg__TaskFeedback.
typedef struct process_msgs__msg__TaskFeedback__Sequence
{
  process_msgs__msg__TaskFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__msg__TaskFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__STRUCT_H_
