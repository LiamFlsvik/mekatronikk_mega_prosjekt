// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/srv/get_scene.h"


#ifndef PROCESS_MSGS__SRV__DETAIL__GET_SCENE__STRUCT_H_
#define PROCESS_MSGS__SRV__DETAIL__GET_SCENE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetScene in the package process_msgs.
typedef struct process_msgs__srv__GetScene_Request
{
  uint8_t structure_needs_at_least_one_member;
} process_msgs__srv__GetScene_Request;

// Struct for a sequence of process_msgs__srv__GetScene_Request.
typedef struct process_msgs__srv__GetScene_Request__Sequence
{
  process_msgs__srv__GetScene_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__srv__GetScene_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'scene'
#include "process_msgs/msg/detail/scene_state__struct.h"

/// Struct defined in srv/GetScene in the package process_msgs.
typedef struct process_msgs__srv__GetScene_Response
{
  process_msgs__msg__SceneState scene;
} process_msgs__srv__GetScene_Response;

// Struct for a sequence of process_msgs__srv__GetScene_Response.
typedef struct process_msgs__srv__GetScene_Response__Sequence
{
  process_msgs__srv__GetScene_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__srv__GetScene_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  process_msgs__srv__GetScene_Event__request__MAX_SIZE = 1
};
// response
enum
{
  process_msgs__srv__GetScene_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetScene in the package process_msgs.
typedef struct process_msgs__srv__GetScene_Event
{
  service_msgs__msg__ServiceEventInfo info;
  process_msgs__srv__GetScene_Request__Sequence request;
  process_msgs__srv__GetScene_Response__Sequence response;
} process_msgs__srv__GetScene_Event;

// Struct for a sequence of process_msgs__srv__GetScene_Event.
typedef struct process_msgs__srv__GetScene_Event__Sequence
{
  process_msgs__srv__GetScene_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} process_msgs__srv__GetScene_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__SRV__DETAIL__GET_SCENE__STRUCT_H_
