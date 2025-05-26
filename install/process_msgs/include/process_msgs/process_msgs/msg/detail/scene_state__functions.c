// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice
#include "process_msgs/msg/detail/scene_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `cubes`
#include "process_msgs/msg/detail/cube_array__functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
process_msgs__msg__SceneState__init(process_msgs__msg__SceneState * msg)
{
  if (!msg) {
    return false;
  }
  // cubes
  if (!process_msgs__msg__CubeArray__init(&msg->cubes)) {
    process_msgs__msg__SceneState__fini(msg);
    return false;
  }
  // cubes_complete
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    process_msgs__msg__SceneState__fini(msg);
    return false;
  }
  return true;
}

void
process_msgs__msg__SceneState__fini(process_msgs__msg__SceneState * msg)
{
  if (!msg) {
    return;
  }
  // cubes
  process_msgs__msg__CubeArray__fini(&msg->cubes);
  // cubes_complete
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
process_msgs__msg__SceneState__are_equal(const process_msgs__msg__SceneState * lhs, const process_msgs__msg__SceneState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cubes
  if (!process_msgs__msg__CubeArray__are_equal(
      &(lhs->cubes), &(rhs->cubes)))
  {
    return false;
  }
  // cubes_complete
  if (lhs->cubes_complete != rhs->cubes_complete) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
process_msgs__msg__SceneState__copy(
  const process_msgs__msg__SceneState * input,
  process_msgs__msg__SceneState * output)
{
  if (!input || !output) {
    return false;
  }
  // cubes
  if (!process_msgs__msg__CubeArray__copy(
      &(input->cubes), &(output->cubes)))
  {
    return false;
  }
  // cubes_complete
  output->cubes_complete = input->cubes_complete;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

process_msgs__msg__SceneState *
process_msgs__msg__SceneState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__SceneState * msg = (process_msgs__msg__SceneState *)allocator.allocate(sizeof(process_msgs__msg__SceneState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__msg__SceneState));
  bool success = process_msgs__msg__SceneState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__msg__SceneState__destroy(process_msgs__msg__SceneState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__msg__SceneState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__msg__SceneState__Sequence__init(process_msgs__msg__SceneState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__SceneState * data = NULL;

  if (size) {
    data = (process_msgs__msg__SceneState *)allocator.zero_allocate(size, sizeof(process_msgs__msg__SceneState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__msg__SceneState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__msg__SceneState__fini(&data[i - 1]);
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
process_msgs__msg__SceneState__Sequence__fini(process_msgs__msg__SceneState__Sequence * array)
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
      process_msgs__msg__SceneState__fini(&array->data[i]);
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

process_msgs__msg__SceneState__Sequence *
process_msgs__msg__SceneState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__SceneState__Sequence * array = (process_msgs__msg__SceneState__Sequence *)allocator.allocate(sizeof(process_msgs__msg__SceneState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__msg__SceneState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__msg__SceneState__Sequence__destroy(process_msgs__msg__SceneState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__msg__SceneState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__msg__SceneState__Sequence__are_equal(const process_msgs__msg__SceneState__Sequence * lhs, const process_msgs__msg__SceneState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__msg__SceneState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__msg__SceneState__Sequence__copy(
  const process_msgs__msg__SceneState__Sequence * input,
  process_msgs__msg__SceneState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__msg__SceneState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__msg__SceneState * data =
      (process_msgs__msg__SceneState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__msg__SceneState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__msg__SceneState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__msg__SceneState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
