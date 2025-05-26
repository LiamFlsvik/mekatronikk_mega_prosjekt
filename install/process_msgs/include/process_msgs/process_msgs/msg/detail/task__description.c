// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from process_msgs:msg/Task.idl
// generated code does not contain a copyright notice

#include "process_msgs/msg/detail/task__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__msg__Task__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x48, 0x21, 0x80, 0x8d, 0x30, 0x01, 0xc8, 0xce,
      0x27, 0x66, 0xdc, 0x21, 0x9f, 0x96, 0xa1, 0x39,
      0x2a, 0xd3, 0x54, 0x85, 0x8d, 0x1a, 0xb2, 0x58,
      0x59, 0xf3, 0x7b, 0xe8, 0x02, 0xe7, 0xd3, 0xff,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char process_msgs__msg__Task__TYPE_NAME[] = "process_msgs/msg/Task";

// Define type names, field names, and default values
static char process_msgs__msg__Task__FIELD_NAME__command[] = "command";

static rosidl_runtime_c__type_description__Field process_msgs__msg__Task__FIELDS[] = {
  {
    {process_msgs__msg__Task__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__msg__Task__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__msg__Task__TYPE_NAME, 21, 21},
      {process_msgs__msg__Task__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string command                     # MOVE_HOME | SCAN | POINT | ...";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__msg__Task__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__msg__Task__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 68, 68},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__msg__Task__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__msg__Task__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
