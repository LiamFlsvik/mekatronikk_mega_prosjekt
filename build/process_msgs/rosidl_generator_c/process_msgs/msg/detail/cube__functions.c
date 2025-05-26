// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice
#include "process_msgs/msg/detail/cube__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `color`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
process_msgs__msg__Cube__init(process_msgs__msg__Cube * msg)
{
  if (!msg) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__init(&msg->color)) {
    process_msgs__msg__Cube__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    process_msgs__msg__Cube__fini(msg);
    return false;
  }
  // angle
  return true;
}

void
process_msgs__msg__Cube__fini(process_msgs__msg__Cube * msg)
{
  if (!msg) {
    return;
  }
  // color
  rosidl_runtime_c__String__fini(&msg->color);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // angle
}

bool
process_msgs__msg__Cube__are_equal(const process_msgs__msg__Cube * lhs, const process_msgs__msg__Cube * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
process_msgs__msg__Cube__copy(
  const process_msgs__msg__Cube * input,
  process_msgs__msg__Cube * output)
{
  if (!input || !output) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // angle
  output->angle = input->angle;
  return true;
}

process_msgs__msg__Cube *
process_msgs__msg__Cube__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__Cube * msg = (process_msgs__msg__Cube *)allocator.allocate(sizeof(process_msgs__msg__Cube), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__msg__Cube));
  bool success = process_msgs__msg__Cube__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__msg__Cube__destroy(process_msgs__msg__Cube * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__msg__Cube__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__msg__Cube__Sequence__init(process_msgs__msg__Cube__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__Cube * data = NULL;

  if (size) {
    data = (process_msgs__msg__Cube *)allocator.zero_allocate(size, sizeof(process_msgs__msg__Cube), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__msg__Cube__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__msg__Cube__fini(&data[i - 1]);
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
process_msgs__msg__Cube__Sequence__fini(process_msgs__msg__Cube__Sequence * array)
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
      process_msgs__msg__Cube__fini(&array->data[i]);
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

process_msgs__msg__Cube__Sequence *
process_msgs__msg__Cube__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__Cube__Sequence * array = (process_msgs__msg__Cube__Sequence *)allocator.allocate(sizeof(process_msgs__msg__Cube__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__msg__Cube__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__msg__Cube__Sequence__destroy(process_msgs__msg__Cube__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__msg__Cube__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__msg__Cube__Sequence__are_equal(const process_msgs__msg__Cube__Sequence * lhs, const process_msgs__msg__Cube__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__msg__Cube__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__msg__Cube__Sequence__copy(
  const process_msgs__msg__Cube__Sequence * input,
  process_msgs__msg__Cube__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__msg__Cube);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__msg__Cube * data =
      (process_msgs__msg__Cube *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__msg__Cube__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__msg__Cube__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__msg__Cube__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
