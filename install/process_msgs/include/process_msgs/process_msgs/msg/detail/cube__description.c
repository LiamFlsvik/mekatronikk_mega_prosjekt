// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice

#include "process_msgs/msg/detail/cube__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__msg__Cube__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x31, 0x67, 0xd7, 0x62, 0x3c, 0x01, 0x99, 0xa8,
      0xcd, 0xf0, 0xc9, 0xf1, 0x5a, 0xf4, 0xf6, 0x7b,
      0x66, 0x6b, 0xe7, 0xb5, 0xd7, 0x17, 0x27, 0x27,
      0x8a, 0x2f, 0x3e, 0x10, 0x7a, 0x58, 0x56, 0x3b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
#endif

static char process_msgs__msg__Cube__TYPE_NAME[] = "process_msgs/msg/Cube";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";

// Define type names, field names, and default values
static char process_msgs__msg__Cube__FIELD_NAME__color[] = "color";
static char process_msgs__msg__Cube__FIELD_NAME__position[] = "position";
static char process_msgs__msg__Cube__FIELD_NAME__angle[] = "angle";

static rosidl_runtime_c__type_description__Field process_msgs__msg__Cube__FIELDS[] = {
  {
    {process_msgs__msg__Cube__FIELD_NAME__color, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__Cube__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__Cube__FIELD_NAME__angle, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription process_msgs__msg__Cube__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__msg__Cube__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__msg__Cube__TYPE_NAME, 21, 21},
      {process_msgs__msg__Cube__FIELDS, 3, 3},
    },
    {process_msgs__msg__Cube__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string               color               # red, yellow, blue, green\n"
  "geometry_msgs/Point  position\n"
  "float32              angle               # angle in degrees or radians (your choice)";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__msg__Cube__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__msg__Cube__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 183, 183},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__msg__Cube__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__msg__Cube__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
