// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice

#include "process_msgs/msg/detail/scene_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__msg__SceneState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x80, 0x1d, 0xe6, 0x69, 0x45, 0x74, 0x73, 0x84,
      0x56, 0x75, 0xb4, 0xcc, 0x16, 0xac, 0x29, 0xa9,
      0x3a, 0xb7, 0x2f, 0x98, 0xa0, 0xdb, 0xa5, 0x9c,
      0x0e, 0xa2, 0xca, 0xec, 0x52, 0x97, 0x7e, 0x5d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "process_msgs/msg/detail/cube__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "process_msgs/msg/detail/cube_array__functions.h"

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
#endif

static char process_msgs__msg__SceneState__TYPE_NAME[] = "process_msgs/msg/SceneState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char process_msgs__msg__Cube__TYPE_NAME[] = "process_msgs/msg/Cube";
static char process_msgs__msg__CubeArray__TYPE_NAME[] = "process_msgs/msg/CubeArray";

// Define type names, field names, and default values
static char process_msgs__msg__SceneState__FIELD_NAME__cubes[] = "cubes";
static char process_msgs__msg__SceneState__FIELD_NAME__cubes_complete[] = "cubes_complete";
static char process_msgs__msg__SceneState__FIELD_NAME__stamp[] = "stamp";

static rosidl_runtime_c__type_description__Field process_msgs__msg__SceneState__FIELDS[] = {
  {
    {process_msgs__msg__SceneState__FIELD_NAME__cubes, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {process_msgs__msg__CubeArray__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__SceneState__FIELD_NAME__cubes_complete, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__SceneState__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription process_msgs__msg__SceneState__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__msg__SceneState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__msg__SceneState__TYPE_NAME, 27, 27},
      {process_msgs__msg__SceneState__FIELDS, 3, 3},
    },
    {process_msgs__msg__SceneState__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
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
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "CubeArray            cubes\n"
  "bool                 cubes_complete  # true when all three colours found\n"
  "builtin_interfaces/Time stamp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__msg__SceneState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__msg__SceneState__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 130, 130},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__msg__SceneState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__msg__SceneState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *process_msgs__msg__Cube__get_individual_type_description_source(NULL);
    sources[4] = *process_msgs__msg__CubeArray__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
