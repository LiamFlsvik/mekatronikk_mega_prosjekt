// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/scene_state.h"


#ifndef PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__STRUCT_H_
#define PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'cubes'
#include "process_msgs/msg/detail/cube_array__struct.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/SceneState in the package process_msgs.
typedef struct process_msgs__msg__SceneState
{
  process_msgs__msg__CubeArray cubes;
  /// true when all three colours found
  bool cubes_complete;
  builtin_interfaces__msg__Time stamp;
} process_msgs__msg__SceneState;

// Struct for a sequence of process_msgs__msg__SceneState.
typedef struct process_msgs__msg__SceneState__Sequence
{
  process_msgs__msg__SceneState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__msg__SceneState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__STRUCT_H_
