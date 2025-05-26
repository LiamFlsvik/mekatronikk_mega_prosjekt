// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

#include "process_msgs/srv/detail/get_scene__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x20, 0x59, 0x3b, 0x93, 0x22, 0x9b, 0xd4, 0xad,
      0x44, 0x5e, 0x5d, 0xf9, 0x4b, 0x51, 0x20, 0xb9,
      0x57, 0x15, 0xf6, 0xa2, 0x5c, 0xd3, 0x90, 0x46,
      0xf8, 0xa2, 0x7a, 0x21, 0xe3, 0x07, 0xe8, 0x9e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0x7b, 0x5d, 0x72, 0x61, 0xdc, 0x10, 0x2c,
      0x5b, 0xbf, 0x28, 0xb1, 0xa8, 0xcf, 0x82, 0x8e,
      0x37, 0xb6, 0x5f, 0x5c, 0x94, 0xa8, 0xdb, 0x70,
      0xce, 0x96, 0xe5, 0xe7, 0x63, 0x05, 0xa4, 0xa0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcf, 0x22, 0x76, 0xfc, 0xfc, 0xb7, 0x71, 0x86,
      0x28, 0x5a, 0xf0, 0x89, 0x9c, 0x85, 0xf2, 0x45,
      0x45, 0xad, 0x5a, 0x48, 0xdf, 0xda, 0x2f, 0xb6,
      0x09, 0xe6, 0x51, 0x49, 0x2d, 0xa0, 0x42, 0x6a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x21, 0xa0, 0x2e, 0xcb, 0xbc, 0xce, 0x66, 0x1e,
      0xcf, 0xbb, 0xf8, 0x0d, 0xeb, 0xbe, 0x74, 0x61,
      0xe3, 0x9a, 0xc3, 0x5c, 0xd8, 0x88, 0xc0, 0xdd,
      0xb6, 0xf9, 0x97, 0x14, 0xe6, 0xe4, 0x5f, 0x28,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "process_msgs/msg/detail/scene_state__functions.h"
#include "process_msgs/msg/detail/cube_array__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "process_msgs/msg/detail/cube__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t process_msgs__msg__Cube__EXPECTED_HASH = {1, {
    0x31, 0x67, 0xd7, 0x62, 0x3c, 0x01, 0x99, 0xa8,
    0xcd, 0xf0, 0xc9, 0xf1, 0x5a, 0xf4, 0xf6, 0x7b,
    0x66, 0x6b, 0xe7, 0xb5, 0xd7, 0x17, 0x27, 0x27,
    0x8a, 0x2f, 0x3e, 0x10, 0x7a, 0x58, 0x56, 0x3b,
  }};
static const rosidl_type_hash_t process_msgs__msg__CubeArray__EXPECTED_HASH = {1, {
    0xde, 0xca, 0xd2, 0xa5, 0x76, 0x2d, 0x4a, 0x30,
    0x83, 0x65, 0x1c, 0x3f, 0x99, 0x55, 0x8b, 0xfa,
    0x09, 0x89, 0x3d, 0x23, 0xce, 0xc8, 0xe3, 0xe5,
    0xef, 0xb4, 0xec, 0x0e, 0x35, 0xc6, 0x22, 0xe6,
  }};
static const rosidl_type_hash_t process_msgs__msg__SceneState__EXPECTED_HASH = {1, {
    0x80, 0x1d, 0xe6, 0x69, 0x45, 0x74, 0x73, 0x84,
    0x56, 0x75, 0xb4, 0xcc, 0x16, 0xac, 0x29, 0xa9,
    0x3a, 0xb7, 0x2f, 0x98, 0xa0, 0xdb, 0xa5, 0x9c,
    0x0e, 0xa2, 0xca, 0xec, 0x52, 0x97, 0x7e, 0x5d,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char process_msgs__srv__GetScene__TYPE_NAME[] = "process_msgs/srv/GetScene";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char process_msgs__msg__Cube__TYPE_NAME[] = "process_msgs/msg/Cube";
static char process_msgs__msg__CubeArray__TYPE_NAME[] = "process_msgs/msg/CubeArray";
static char process_msgs__msg__SceneState__TYPE_NAME[] = "process_msgs/msg/SceneState";
static char process_msgs__srv__GetScene_Event__TYPE_NAME[] = "process_msgs/srv/GetScene_Event";
static char process_msgs__srv__GetScene_Request__TYPE_NAME[] = "process_msgs/srv/GetScene_Request";
static char process_msgs__srv__GetScene_Response__TYPE_NAME[] = "process_msgs/srv/GetScene_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char process_msgs__srv__GetScene__FIELD_NAME__request_message[] = "request_message";
static char process_msgs__srv__GetScene__FIELD_NAME__response_message[] = "response_message";
static char process_msgs__srv__GetScene__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field process_msgs__srv__GetScene__FIELDS[] = {
  {
    {process_msgs__srv__GetScene__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {process_msgs__srv__GetScene_Request__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {process_msgs__srv__GetScene_Response__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {process_msgs__srv__GetScene_Event__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription process_msgs__srv__GetScene__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__Cube__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__CubeArray__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__SceneState__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Event__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Request__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Response__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__srv__GetScene__TYPE_NAME, 25, 25},
      {process_msgs__srv__GetScene__FIELDS, 3, 3},
    },
    {process_msgs__srv__GetScene__REFERENCED_TYPE_DESCRIPTIONS, 9, 9},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__Cube__EXPECTED_HASH, process_msgs__msg__Cube__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = process_msgs__msg__Cube__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__CubeArray__EXPECTED_HASH, process_msgs__msg__CubeArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = process_msgs__msg__CubeArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__SceneState__EXPECTED_HASH, process_msgs__msg__SceneState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = process_msgs__msg__SceneState__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = process_msgs__srv__GetScene_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = process_msgs__srv__GetScene_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[7].fields = process_msgs__srv__GetScene_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char process_msgs__srv__GetScene_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field process_msgs__srv__GetScene_Request__FIELDS[] = {
  {
    {process_msgs__srv__GetScene_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__srv__GetScene_Request__TYPE_NAME, 33, 33},
      {process_msgs__srv__GetScene_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char process_msgs__srv__GetScene_Response__FIELD_NAME__scene[] = "scene";

static rosidl_runtime_c__type_description__Field process_msgs__srv__GetScene_Response__FIELDS[] = {
  {
    {process_msgs__srv__GetScene_Response__FIELD_NAME__scene, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {process_msgs__msg__SceneState__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription process_msgs__srv__GetScene_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__Cube__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__CubeArray__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__SceneState__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__srv__GetScene_Response__TYPE_NAME, 34, 34},
      {process_msgs__srv__GetScene_Response__FIELDS, 1, 1},
    },
    {process_msgs__srv__GetScene_Response__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__Cube__EXPECTED_HASH, process_msgs__msg__Cube__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = process_msgs__msg__Cube__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__CubeArray__EXPECTED_HASH, process_msgs__msg__CubeArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = process_msgs__msg__CubeArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__SceneState__EXPECTED_HASH, process_msgs__msg__SceneState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = process_msgs__msg__SceneState__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char process_msgs__srv__GetScene_Event__FIELD_NAME__info[] = "info";
static char process_msgs__srv__GetScene_Event__FIELD_NAME__request[] = "request";
static char process_msgs__srv__GetScene_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field process_msgs__srv__GetScene_Event__FIELDS[] = {
  {
    {process_msgs__srv__GetScene_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {process_msgs__srv__GetScene_Request__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {process_msgs__srv__GetScene_Response__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription process_msgs__srv__GetScene_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__Cube__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__CubeArray__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__SceneState__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Request__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {process_msgs__srv__GetScene_Response__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__srv__GetScene_Event__TYPE_NAME, 31, 31},
      {process_msgs__srv__GetScene_Event__FIELDS, 3, 3},
    },
    {process_msgs__srv__GetScene_Event__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__Cube__EXPECTED_HASH, process_msgs__msg__Cube__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = process_msgs__msg__Cube__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__CubeArray__EXPECTED_HASH, process_msgs__msg__CubeArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = process_msgs__msg__CubeArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&process_msgs__msg__SceneState__EXPECTED_HASH, process_msgs__msg__SceneState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = process_msgs__msg__SceneState__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = process_msgs__srv__GetScene_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = process_msgs__srv__GetScene_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# --- Request (empty) ---\n"
  "\n"
  "---\n"
  "# --- Response ---\n"
  "SceneState scene";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__srv__GetScene__TYPE_NAME, 25, 25},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 67, 67},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__srv__GetScene_Request__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__srv__GetScene_Response__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__srv__GetScene_Event__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[10];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 10, 10};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__srv__GetScene__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *process_msgs__msg__Cube__get_individual_type_description_source(NULL);
    sources[4] = *process_msgs__msg__CubeArray__get_individual_type_description_source(NULL);
    sources[5] = *process_msgs__msg__SceneState__get_individual_type_description_source(NULL);
    sources[6] = *process_msgs__srv__GetScene_Event__get_individual_type_description_source(NULL);
    sources[7] = *process_msgs__srv__GetScene_Request__get_individual_type_description_source(NULL);
    sources[8] = *process_msgs__srv__GetScene_Response__get_individual_type_description_source(NULL);
    sources[9] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__srv__GetScene_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__srv__GetScene_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *process_msgs__msg__Cube__get_individual_type_description_source(NULL);
    sources[4] = *process_msgs__msg__CubeArray__get_individual_type_description_source(NULL);
    sources[5] = *process_msgs__msg__SceneState__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__srv__GetScene_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *process_msgs__msg__Cube__get_individual_type_description_source(NULL);
    sources[4] = *process_msgs__msg__CubeArray__get_individual_type_description_source(NULL);
    sources[5] = *process_msgs__msg__SceneState__get_individual_type_description_source(NULL);
    sources[6] = *process_msgs__srv__GetScene_Request__get_individual_type_description_source(NULL);
    sources[7] = *process_msgs__srv__GetScene_Response__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
