// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice

#include "process_msgs/msg/detail/task_feedback__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__msg__TaskFeedback__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1e, 0xc0, 0x21, 0x83, 0xfa, 0x68, 0xdb, 0xd1,
      0xf7, 0xb5, 0xfb, 0xa7, 0x6b, 0x18, 0x84, 0xfa,
      0xad, 0x9b, 0x2b, 0x0c, 0xbf, 0xae, 0x9d, 0x0a,
      0x6d, 0x57, 0x57, 0xa7, 0x34, 0x1b, 0xf4, 0x71,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char process_msgs__msg__TaskFeedback__TYPE_NAME[] = "process_msgs/msg/TaskFeedback";

// Define type names, field names, and default values
static char process_msgs__msg__TaskFeedback__FIELD_NAME__command[] = "command";
static char process_msgs__msg__TaskFeedback__FIELD_NAME__success[] = "success";
static char process_msgs__msg__TaskFeedback__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field process_msgs__msg__TaskFeedback__FIELDS[] = {
  {
    {process_msgs__msg__TaskFeedback__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__TaskFeedback__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {process_msgs__msg__TaskFeedback__FIELD_NAME__message, 7, 7},
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
process_msgs__msg__TaskFeedback__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {process_msgs__msg__TaskFeedback__TYPE_NAME, 29, 29},
      {process_msgs__msg__TaskFeedback__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string command                     # echoes the command just executed\n"
  "bool   success                     # true = finished OK\n"
  "string message                     # optional human-readable info";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
process_msgs__msg__TaskFeedback__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {process_msgs__msg__TaskFeedback__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 192, 192},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__msg__TaskFeedback__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *process_msgs__msg__TaskFeedback__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
