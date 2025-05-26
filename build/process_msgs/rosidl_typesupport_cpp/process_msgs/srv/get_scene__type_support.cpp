// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "process_msgs/srv/detail/get_scene__functions.h"
#include "process_msgs/srv/detail/get_scene__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace process_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetScene_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetScene_Request_type_support_ids_t;

static const _GetScene_Request_type_support_ids_t _GetScene_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetScene_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetScene_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetScene_Request_type_support_symbol_names_t _GetScene_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, process_msgs, srv, GetScene_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, srv, GetScene_Request)),
  }
};

typedef struct _GetScene_Request_type_support_data_t
{
  void * data[2];
} _GetScene_Request_type_support_data_t;

static _GetScene_Request_type_support_data_t _GetScene_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetScene_Request_message_typesupport_map = {
  2,
  "process_msgs",
  &_GetScene_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetScene_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetScene_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetScene_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetScene_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &process_msgs__srv__GetScene_Request__get_type_hash,
  &process_msgs__srv__GetScene_Request__get_type_description,
  &process_msgs__srv__GetScene_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::srv::GetScene_Request>()
{
  return &::process_msgs::srv::rosidl_typesupport_cpp::GetScene_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, process_msgs, srv, GetScene_Request)() {
  return get_message_type_support_handle<process_msgs::srv::GetScene_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__functions.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace process_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetScene_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetScene_Response_type_support_ids_t;

static const _GetScene_Response_type_support_ids_t _GetScene_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetScene_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetScene_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetScene_Response_type_support_symbol_names_t _GetScene_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, process_msgs, srv, GetScene_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, srv, GetScene_Response)),
  }
};

typedef struct _GetScene_Response_type_support_data_t
{
  void * data[2];
} _GetScene_Response_type_support_data_t;

static _GetScene_Response_type_support_data_t _GetScene_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetScene_Response_message_typesupport_map = {
  2,
  "process_msgs",
  &_GetScene_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetScene_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetScene_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetScene_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetScene_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &process_msgs__srv__GetScene_Response__get_type_hash,
  &process_msgs__srv__GetScene_Response__get_type_description,
  &process_msgs__srv__GetScene_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::srv::GetScene_Response>()
{
  return &::process_msgs::srv::rosidl_typesupport_cpp::GetScene_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, process_msgs, srv, GetScene_Response)() {
  return get_message_type_support_handle<process_msgs::srv::GetScene_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__functions.h"
// already included above
// #include "process_msgs/srv/detail/get_scene__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace process_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetScene_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetScene_Event_type_support_ids_t;

static const _GetScene_Event_type_support_ids_t _GetScene_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetScene_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetScene_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetScene_Event_type_support_symbol_names_t _GetScene_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, process_msgs, srv, GetScene_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, srv, GetScene_Event)),
  }
};

typedef struct _GetScene_Event_type_support_data_t
{
  void * data[2];
} _GetScene_Event_type_support_data_t;

static _GetScene_Event_type_support_data_t _GetScene_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetScene_Event_message_typesupport_map = {
  2,
  "process_msgs",
  &_GetScene_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GetScene_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GetScene_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetScene_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetScene_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &process_msgs__srv__GetScene_Event__get_type_hash,
  &process_msgs__srv__GetScene_Event__get_type_description,
  &process_msgs__srv__GetScene_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<process_msgs::srv::GetScene_Event>()
{
  return &::process_msgs::srv::rosidl_typesupport_cpp::GetScene_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, process_msgs, srv, GetScene_Event)() {
  return get_message_type_support_handle<process_msgs::srv::GetScene_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "process_msgs/srv/detail/get_scene__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace process_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetScene_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetScene_type_support_ids_t;

static const _GetScene_type_support_ids_t _GetScene_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetScene_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetScene_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetScene_type_support_symbol_names_t _GetScene_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, process_msgs, srv, GetScene)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, process_msgs, srv, GetScene)),
  }
};

typedef struct _GetScene_type_support_data_t
{
  void * data[2];
} _GetScene_type_support_data_t;

static _GetScene_type_support_data_t _GetScene_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetScene_service_typesupport_map = {
  2,
  "process_msgs",
  &_GetScene_service_typesupport_ids.typesupport_identifier[0],
  &_GetScene_service_typesupport_symbol_names.symbol_name[0],
  &_GetScene_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetScene_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetScene_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<process_msgs::srv::GetScene_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<process_msgs::srv::GetScene_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<process_msgs::srv::GetScene_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<process_msgs::srv::GetScene>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<process_msgs::srv::GetScene>,
  &process_msgs__srv__GetScene__get_type_hash,
  &process_msgs__srv__GetScene__get_type_description,
  &process_msgs__srv__GetScene__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace process_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<process_msgs::srv::GetScene>()
{
  return &::process_msgs::srv::rosidl_typesupport_cpp::GetScene_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, process_msgs, srv, GetScene)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<process_msgs::srv::GetScene>();
}

#ifdef __cplusplus
}
#endif
