// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

#include "process_msgs/msg/detail/key_event__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__msg__KeyEvent__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x20, 0xc7, 0xe8, 0xa5, 0x02, 0xf4, 0x87, 0xc9,
      0x3d, 0x93, 0xcc, 0x39, 0x13, 0x1e, 0xa4, 0xce,
      0x3c, 0x95, 0x78, 0xe5, 0x8e, 0x1c, 0x95, 0x56,
      0x76, 0x76, 0x8b, 0xbb, 0xf8, 0xc7, 0x5e, 0x72,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char process_msgs__msg__KeyEvent__TYPE_NAME[] = "process_msgs/msg/KeyEvent";

// Define type names, field names, and default values
static char process_msgs__msg__KeyEvent__FIELD_NAME__active_keys[] = "active_keys";

static rosidl_runtime_c__type_description__Field process_msgs__msg__KeyEvent__FIELDS[] = {
  {
    {process_msgs__msg__KeyEvent__FIELD_NAME__active_keys, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__msg__KeyEvent__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__msg__KeyEvent__TYPE_NAME, 25, 25},
      {process_msgs__msg__KeyEvent__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string[] active_keys";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__msg__KeyEvent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__msg__KeyEvent__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 20, 20},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__msg__KeyEvent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__msg__KeyEvent__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
