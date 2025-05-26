// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "process_msgs/msg/detail/cube__rosidl_typesupport_introspection_c.h"
#include "process_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "process_msgs/msg/detail/cube__functions.h"
#include "process_msgs/msg/detail/cube__struct.h"


// Include directives for member types
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  process_msgs__msg__Cube__init(message_memory);
}

void process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_fini_function(void * message_memory)
{
  process_msgs__msg__Cube__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_member_array[3] = {
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__msg__Cube, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__msg__Cube, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__msg__Cube, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_members = {
  "process_msgs__msg",  // message namespace
  "Cube",  // message name
  3,  // number of fields
  sizeof(process_msgs__msg__Cube),
  false,  // has_any_key_member_
  process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_member_array,  // message members
  process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_init_function,  // function to initialize message memory (memory has to be allocated)
  process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_type_support_handle = {
  0,
  &process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__msg__Cube__get_type_hash,
  &process_msgs__msg__Cube__get_type_description,
  &process_msgs__msg__Cube__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_process_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, msg, Cube)() {
  process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_type_support_handle.typesupport_identifier) {
    process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &process_msgs__msg__Cube__rosidl_typesupport_introspection_c__Cube_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
