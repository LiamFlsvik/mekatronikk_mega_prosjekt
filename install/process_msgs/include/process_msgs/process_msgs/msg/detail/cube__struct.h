// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube.h"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE__STRUCT_H_
#define PROCESS_MSGS__MSG__DETAIL__CUBE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'color'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Cube in the package process_msgs.
typedef struct process_msgs__msg__Cube
{
  /// red, yellow, blue, green
  rosidl_runtime_c__String color;
  geometry_msgs__msg__Point position;
  /// angle in degrees or radians (your choice)
  float angle;
} process_msgs__msg__Cube;

// Struct for a sequence of process_msgs__msg__Cube.
typedef struct process_msgs__msg__Cube__Sequence
{
  process_msgs__msg__Cube * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__msg__Cube__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE__STRUCT_H_
