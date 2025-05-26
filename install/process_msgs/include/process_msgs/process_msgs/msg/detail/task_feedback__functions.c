// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice
#include "process_msgs/msg/detail/task_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `command`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
process_msgs__msg__TaskFeedback__init(process_msgs__msg__TaskFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    process_msgs__msg__TaskFeedback__fini(msg);
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    process_msgs__msg__TaskFeedback__fini(msg);
    return false;
  }
  return true;
}

void
process_msgs__msg__TaskFeedback__fini(process_msgs__msg__TaskFeedback * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
process_msgs__msg__TaskFeedback__are_equal(const process_msgs__msg__TaskFeedback * lhs, const process_msgs__msg__TaskFeedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
process_msgs__msg__TaskFeedback__copy(
  const process_msgs__msg__TaskFeedback * input,
  process_msgs__msg__TaskFeedback * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

process_msgs__msg__TaskFeedback *
process_msgs__msg__TaskFeedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__TaskFeedback * msg = (process_msgs__msg__TaskFeedback *)allocator.allocate(sizeof(process_msgs__msg__TaskFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__msg__TaskFeedback));
  bool success = process_msgs__msg__TaskFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__msg__TaskFeedback__destroy(process_msgs__msg__TaskFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__msg__TaskFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__msg__TaskFeedback__Sequence__init(process_msgs__msg__TaskFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__TaskFeedback * data = NULL;

  if (size) {
    data = (process_msgs__msg__TaskFeedback *)allocator.zero_allocate(size, sizeof(process_msgs__msg__TaskFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__msg__TaskFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__msg__TaskFeedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
process_msgs__msg__TaskFeedback__Sequence__fini(process_msgs__msg__TaskFeedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      process_msgs__msg__TaskFeedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

process_msgs__msg__TaskFeedback__Sequence *
process_msgs__msg__TaskFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__TaskFeedback__Sequence * array = (process_msgs__msg__TaskFeedback__Sequence *)allocator.allocate(sizeof(process_msgs__msg__TaskFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__msg__TaskFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__msg__TaskFeedback__Sequence__destroy(process_msgs__msg__TaskFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__msg__TaskFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__msg__TaskFeedback__Sequence__are_equal(const process_msgs__msg__TaskFeedback__Sequence * lhs, const process_msgs__msg__TaskFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__msg__TaskFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__msg__TaskFeedback__Sequence__copy(
  const process_msgs__msg__TaskFeedback__Sequence * input,
  process_msgs__msg__TaskFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__msg__TaskFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__msg__TaskFeedback * data =
      (process_msgs__msg__TaskFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__msg__TaskFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__msg__TaskFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__msg__TaskFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
