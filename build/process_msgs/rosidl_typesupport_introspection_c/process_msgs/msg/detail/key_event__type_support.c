// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "process_msgs/msg/detail/key_event__rosidl_typesupport_introspection_c.h"
#include "process_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "process_msgs/msg/detail/key_event__functions.h"
#include "process_msgs/msg/detail/key_event__struct.h"


// Include directives for member types
// Member `active_keys`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  process_msgs__msg__KeyEvent__init(message_memory);
}

void process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_fini_function(void * message_memory)
{
  process_msgs__msg__KeyEvent__fini(message_memory);
}

size_t process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__size_function__KeyEvent__active_keys(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__get_const_function__KeyEvent__active_keys(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__get_function__KeyEvent__active_keys(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__fetch_function__KeyEvent__active_keys(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__get_const_function__KeyEvent__active_keys(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__assign_function__KeyEvent__active_keys(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__get_function__KeyEvent__active_keys(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__resize_function__KeyEvent__active_keys(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_member_array[1] = {
  {
    "active_keys",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__msg__KeyEvent, active_keys),  // bytes offset in struct
    NULL,  // default value
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__size_function__KeyEvent__active_keys,  // size() function pointer
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__get_const_function__KeyEvent__active_keys,  // get_const(index) function pointer
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__get_function__KeyEvent__active_keys,  // get(index) function pointer
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__fetch_function__KeyEvent__active_keys,  // fetch(index, &value) function pointer
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__assign_function__KeyEvent__active_keys,  // assign(index, value) function pointer
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__resize_function__KeyEvent__active_keys  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_members = {
  "process_msgs__msg",  // message namespace
  "KeyEvent",  // message name
  1,  // number of fields
  sizeof(process_msgs__msg__KeyEvent),
  false,  // has_any_key_member_
  process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_member_array,  // message members
  process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_init_function,  // function to initialize message memory (memory has to be allocated)
  process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_type_support_handle = {
  0,
  &process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__msg__KeyEvent__get_type_hash,
  &process_msgs__msg__KeyEvent__get_type_description,
  &process_msgs__msg__KeyEvent__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_process_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, msg, KeyEvent)() {
  if (!process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_type_support_handle.typesupport_identifier) {
    process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &process_msgs__msg__KeyEvent__rosidl_typesupport_introspection_c__KeyEvent_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
