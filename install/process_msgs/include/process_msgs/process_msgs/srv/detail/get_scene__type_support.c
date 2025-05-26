// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "process_msgs/srv/detail/get_scene__rosidl_typesupport_introspection_c.h"
#include "process_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "process_msgs/srv/detail/get_scene__functions.h"
#include "process_msgs/srv/detail/get_scene__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  process_msgs__srv__GetScene_Request__init(message_memory);
}

void process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_fini_function(void * message_memory)
{
  process_msgs__srv__GetScene_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__srv__GetScene_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_members = {
  "process_msgs__srv",  // message namespace
  "GetScene_Request",  // message name
  1,  // number of fields
  sizeof(process_msgs__srv__GetScene_Request),
  false,  // has_any_key_member_
  process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_member_array,  // message members
  process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_type_support_handle = {
  0,
  &process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__srv__GetScene_Request__get_type_hash,
  &process_msgs__srv__GetScene_Request__get_type_description,
  &process_msgs__srv__GetScene_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_process_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Request)() {
  if (!process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_type_support_handle.typesupport_identifier) {
    process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "process_msgs/srv/detail/get_scene__rosidl_typesupport_introspection_c.h"
// already included above
// #include "process_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__functions.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__struct.h"


// Include directives for member types
// Member `scene`
#include "process_msgs/msg/scene_state.h"
// Member `scene`
#include "process_msgs/msg/detail/scene_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  process_msgs__srv__GetScene_Response__init(message_memory);
}

void process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_fini_function(void * message_memory)
{
  process_msgs__srv__GetScene_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_member_array[1] = {
  {
    "scene",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__srv__GetScene_Response, scene),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_members = {
  "process_msgs__srv",  // message namespace
  "GetScene_Response",  // message name
  1,  // number of fields
  sizeof(process_msgs__srv__GetScene_Response),
  false,  // has_any_key_member_
  process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_member_array,  // message members
  process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle = {
  0,
  &process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__srv__GetScene_Response__get_type_hash,
  &process_msgs__srv__GetScene_Response__get_type_description,
  &process_msgs__srv__GetScene_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_process_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Response)() {
  process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, msg, SceneState)();
  if (!process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle.typesupport_identifier) {
    process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "process_msgs/srv/detail/get_scene__rosidl_typesupport_introspection_c.h"
// already included above
// #include "process_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__functions.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "process_msgs/srv/get_scene.h"
// Member `request`
// Member `response`
// already included above
// #include "process_msgs/srv/detail/get_scene__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  process_msgs__srv__GetScene_Event__init(message_memory);
}

void process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_fini_function(void * message_memory)
{
  process_msgs__srv__GetScene_Event__fini(message_memory);
}

size_t process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__size_function__GetScene_Event__request(
  const void * untyped_member)
{
  const process_msgs__srv__GetScene_Request__Sequence * member =
    (const process_msgs__srv__GetScene_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_const_function__GetScene_Event__request(
  const void * untyped_member, size_t index)
{
  const process_msgs__srv__GetScene_Request__Sequence * member =
    (const process_msgs__srv__GetScene_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_function__GetScene_Event__request(
  void * untyped_member, size_t index)
{
  process_msgs__srv__GetScene_Request__Sequence * member =
    (process_msgs__srv__GetScene_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__fetch_function__GetScene_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const process_msgs__srv__GetScene_Request * item =
    ((const process_msgs__srv__GetScene_Request *)
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_const_function__GetScene_Event__request(untyped_member, index));
  process_msgs__srv__GetScene_Request * value =
    (process_msgs__srv__GetScene_Request *)(untyped_value);
  *value = *item;
}

void process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__assign_function__GetScene_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  process_msgs__srv__GetScene_Request * item =
    ((process_msgs__srv__GetScene_Request *)
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_function__GetScene_Event__request(untyped_member, index));
  const process_msgs__srv__GetScene_Request * value =
    (const process_msgs__srv__GetScene_Request *)(untyped_value);
  *item = *value;
}

bool process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__resize_function__GetScene_Event__request(
  void * untyped_member, size_t size)
{
  process_msgs__srv__GetScene_Request__Sequence * member =
    (process_msgs__srv__GetScene_Request__Sequence *)(untyped_member);
  process_msgs__srv__GetScene_Request__Sequence__fini(member);
  return process_msgs__srv__GetScene_Request__Sequence__init(member, size);
}

size_t process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__size_function__GetScene_Event__response(
  const void * untyped_member)
{
  const process_msgs__srv__GetScene_Response__Sequence * member =
    (const process_msgs__srv__GetScene_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_const_function__GetScene_Event__response(
  const void * untyped_member, size_t index)
{
  const process_msgs__srv__GetScene_Response__Sequence * member =
    (const process_msgs__srv__GetScene_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_function__GetScene_Event__response(
  void * untyped_member, size_t index)
{
  process_msgs__srv__GetScene_Response__Sequence * member =
    (process_msgs__srv__GetScene_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__fetch_function__GetScene_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const process_msgs__srv__GetScene_Response * item =
    ((const process_msgs__srv__GetScene_Response *)
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_const_function__GetScene_Event__response(untyped_member, index));
  process_msgs__srv__GetScene_Response * value =
    (process_msgs__srv__GetScene_Response *)(untyped_value);
  *value = *item;
}

void process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__assign_function__GetScene_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  process_msgs__srv__GetScene_Response * item =
    ((process_msgs__srv__GetScene_Response *)
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_function__GetScene_Event__response(untyped_member, index));
  const process_msgs__srv__GetScene_Response * value =
    (const process_msgs__srv__GetScene_Response *)(untyped_value);
  *item = *value;
}

bool process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__resize_function__GetScene_Event__response(
  void * untyped_member, size_t size)
{
  process_msgs__srv__GetScene_Response__Sequence * member =
    (process_msgs__srv__GetScene_Response__Sequence *)(untyped_member);
  process_msgs__srv__GetScene_Response__Sequence__fini(member);
  return process_msgs__srv__GetScene_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(process_msgs__srv__GetScene_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(process_msgs__srv__GetScene_Event, request),  // bytes offset in struct
    NULL,  // default value
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__size_function__GetScene_Event__request,  // size() function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_const_function__GetScene_Event__request,  // get_const(index) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_function__GetScene_Event__request,  // get(index) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__fetch_function__GetScene_Event__request,  // fetch(index, &value) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__assign_function__GetScene_Event__request,  // assign(index, value) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__resize_function__GetScene_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(process_msgs__srv__GetScene_Event, response),  // bytes offset in struct
    NULL,  // default value
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__size_function__GetScene_Event__response,  // size() function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_const_function__GetScene_Event__response,  // get_const(index) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__get_function__GetScene_Event__response,  // get(index) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__fetch_function__GetScene_Event__response,  // fetch(index, &value) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__assign_function__GetScene_Event__response,  // assign(index, value) function pointer
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__resize_function__GetScene_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_members = {
  "process_msgs__srv",  // message namespace
  "GetScene_Event",  // message name
  3,  // number of fields
  sizeof(process_msgs__srv__GetScene_Event),
  false,  // has_any_key_member_
  process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_member_array,  // message members
  process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_type_support_handle = {
  0,
  &process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_members,
  get_message_typesupport_handle_function,
  &process_msgs__srv__GetScene_Event__get_type_hash,
  &process_msgs__srv__GetScene_Event__get_type_description,
  &process_msgs__srv__GetScene_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_process_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Event)() {
  process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Request)();
  process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Response)();
  if (!process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_type_support_handle.typesupport_identifier) {
    process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "process_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_members = {
  "process_msgs__srv",  // service namespace
  "GetScene",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_Request_message_type_support_handle,
  NULL,  // response message
  // process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle
  NULL  // event_message
  // process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle
};


static rosidl_service_type_support_t process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_type_support_handle = {
  0,
  &process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_members,
  get_service_typesupport_handle_function,
  &process_msgs__srv__GetScene_Request__rosidl_typesupport_introspection_c__GetScene_Request_message_type_support_handle,
  &process_msgs__srv__GetScene_Response__rosidl_typesupport_introspection_c__GetScene_Response_message_type_support_handle,
  &process_msgs__srv__GetScene_Event__rosidl_typesupport_introspection_c__GetScene_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    process_msgs,
    srv,
    GetScene
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    process_msgs,
    srv,
    GetScene
  ),
  &process_msgs__srv__GetScene__get_type_hash,
  &process_msgs__srv__GetScene__get_type_description,
  &process_msgs__srv__GetScene__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_process_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene)(void) {
  if (!process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_type_support_handle.typesupport_identifier) {
    process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, process_msgs, srv, GetScene_Event)()->data;
  }

  return &process_msgs__srv__detail__get_scene__rosidl_typesupport_introspection_c__GetScene_service_type_support_handle;
}
