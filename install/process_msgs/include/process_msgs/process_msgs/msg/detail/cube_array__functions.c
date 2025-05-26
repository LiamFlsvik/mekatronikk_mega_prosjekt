// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from process_msgs:msg/CubeArray.idl
// generated code does not contain a copyright notice
#include "process_msgs/msg/detail/cube_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `cubes`
#include "process_msgs/msg/detail/cube__functions.h"

bool
process_msgs__msg__CubeArray__init(process_msgs__msg__CubeArray * msg)
{
  if (!msg) {
    return false;
  }
  // cubes
  if (!process_msgs__msg__Cube__Sequence__init(&msg->cubes, 0)) {
    process_msgs__msg__CubeArray__fini(msg);
    return false;
  }
  return true;
}

void
process_msgs__msg__CubeArray__fini(process_msgs__msg__CubeArray * msg)
{
  if (!msg) {
    return;
  }
  // cubes
  process_msgs__msg__Cube__Sequence__fini(&msg->cubes);
}

bool
process_msgs__msg__CubeArray__are_equal(const process_msgs__msg__CubeArray * lhs, const process_msgs__msg__CubeArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cubes
  if (!process_msgs__msg__Cube__Sequence__are_equal(
      &(lhs->cubes), &(rhs->cubes)))
  {
    return false;
  }
  return true;
}

bool
process_msgs__msg__CubeArray__copy(
  const process_msgs__msg__CubeArray * input,
  process_msgs__msg__CubeArray * output)
{
  if (!input || !output) {
    return false;
  }
  // cubes
  if (!process_msgs__msg__Cube__Sequence__copy(
      &(input->cubes), &(output->cubes)))
  {
    return false;
  }
  return true;
}

process_msgs__msg__CubeArray *
process_msgs__msg__CubeArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__CubeArray * msg = (process_msgs__msg__CubeArray *)allocator.allocate(sizeof(process_msgs__msg__CubeArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__msg__CubeArray));
  bool success = process_msgs__msg__CubeArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__msg__CubeArray__destroy(process_msgs__msg__CubeArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__msg__CubeArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__msg__CubeArray__Sequence__init(process_msgs__msg__CubeArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__CubeArray * data = NULL;

  if (size) {
    data = (process_msgs__msg__CubeArray *)allocator.zero_allocate(size, sizeof(process_msgs__msg__CubeArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__msg__CubeArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__msg__CubeArray__fini(&data[i - 1]);
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
process_msgs__msg__CubeArray__Sequence__fini(process_msgs__msg__CubeArray__Sequence * array)
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
      process_msgs__msg__CubeArray__fini(&array->data[i]);
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

process_msgs__msg__CubeArray__Sequence *
process_msgs__msg__CubeArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__msg__CubeArray__Sequence * array = (process_msgs__msg__CubeArray__Sequence *)allocator.allocate(sizeof(process_msgs__msg__CubeArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__msg__CubeArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__msg__CubeArray__Sequence__destroy(process_msgs__msg__CubeArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__msg__CubeArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__msg__CubeArray__Sequence__are_equal(const process_msgs__msg__CubeArray__Sequence * lhs, const process_msgs__msg__CubeArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__msg__CubeArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__msg__CubeArray__Sequence__copy(
  const process_msgs__msg__CubeArray__Sequence * input,
  process_msgs__msg__CubeArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__msg__CubeArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__msg__CubeArray * data =
      (process_msgs__msg__CubeArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__msg__CubeArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__msg__CubeArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__msg__CubeArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
