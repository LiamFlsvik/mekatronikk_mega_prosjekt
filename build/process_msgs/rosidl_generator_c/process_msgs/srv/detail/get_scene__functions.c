// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice
#include "process_msgs/srv/detail/get_scene__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
process_msgs__srv__GetScene_Request__init(process_msgs__srv__GetScene_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
process_msgs__srv__GetScene_Request__fini(process_msgs__srv__GetScene_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
process_msgs__srv__GetScene_Request__are_equal(const process_msgs__srv__GetScene_Request * lhs, const process_msgs__srv__GetScene_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
process_msgs__srv__GetScene_Request__copy(
  const process_msgs__srv__GetScene_Request * input,
  process_msgs__srv__GetScene_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

process_msgs__srv__GetScene_Request *
process_msgs__srv__GetScene_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Request * msg = (process_msgs__srv__GetScene_Request *)allocator.allocate(sizeof(process_msgs__srv__GetScene_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__srv__GetScene_Request));
  bool success = process_msgs__srv__GetScene_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__srv__GetScene_Request__destroy(process_msgs__srv__GetScene_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__srv__GetScene_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__srv__GetScene_Request__Sequence__init(process_msgs__srv__GetScene_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Request * data = NULL;

  if (size) {
    data = (process_msgs__srv__GetScene_Request *)allocator.zero_allocate(size, sizeof(process_msgs__srv__GetScene_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__srv__GetScene_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__srv__GetScene_Request__fini(&data[i - 1]);
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
process_msgs__srv__GetScene_Request__Sequence__fini(process_msgs__srv__GetScene_Request__Sequence * array)
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
      process_msgs__srv__GetScene_Request__fini(&array->data[i]);
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

process_msgs__srv__GetScene_Request__Sequence *
process_msgs__srv__GetScene_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Request__Sequence * array = (process_msgs__srv__GetScene_Request__Sequence *)allocator.allocate(sizeof(process_msgs__srv__GetScene_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__srv__GetScene_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__srv__GetScene_Request__Sequence__destroy(process_msgs__srv__GetScene_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__srv__GetScene_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__srv__GetScene_Request__Sequence__are_equal(const process_msgs__srv__GetScene_Request__Sequence * lhs, const process_msgs__srv__GetScene_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__srv__GetScene_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__srv__GetScene_Request__Sequence__copy(
  const process_msgs__srv__GetScene_Request__Sequence * input,
  process_msgs__srv__GetScene_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__srv__GetScene_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__srv__GetScene_Request * data =
      (process_msgs__srv__GetScene_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__srv__GetScene_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__srv__GetScene_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__srv__GetScene_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `scene`
#include "process_msgs/msg/detail/scene_state__functions.h"

bool
process_msgs__srv__GetScene_Response__init(process_msgs__srv__GetScene_Response * msg)
{
  if (!msg) {
    return false;
  }
  // scene
  if (!process_msgs__msg__SceneState__init(&msg->scene)) {
    process_msgs__srv__GetScene_Response__fini(msg);
    return false;
  }
  return true;
}

void
process_msgs__srv__GetScene_Response__fini(process_msgs__srv__GetScene_Response * msg)
{
  if (!msg) {
    return;
  }
  // scene
  process_msgs__msg__SceneState__fini(&msg->scene);
}

bool
process_msgs__srv__GetScene_Response__are_equal(const process_msgs__srv__GetScene_Response * lhs, const process_msgs__srv__GetScene_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // scene
  if (!process_msgs__msg__SceneState__are_equal(
      &(lhs->scene), &(rhs->scene)))
  {
    return false;
  }
  return true;
}

bool
process_msgs__srv__GetScene_Response__copy(
  const process_msgs__srv__GetScene_Response * input,
  process_msgs__srv__GetScene_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // scene
  if (!process_msgs__msg__SceneState__copy(
      &(input->scene), &(output->scene)))
  {
    return false;
  }
  return true;
}

process_msgs__srv__GetScene_Response *
process_msgs__srv__GetScene_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Response * msg = (process_msgs__srv__GetScene_Response *)allocator.allocate(sizeof(process_msgs__srv__GetScene_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__srv__GetScene_Response));
  bool success = process_msgs__srv__GetScene_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__srv__GetScene_Response__destroy(process_msgs__srv__GetScene_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__srv__GetScene_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__srv__GetScene_Response__Sequence__init(process_msgs__srv__GetScene_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Response * data = NULL;

  if (size) {
    data = (process_msgs__srv__GetScene_Response *)allocator.zero_allocate(size, sizeof(process_msgs__srv__GetScene_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__srv__GetScene_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__srv__GetScene_Response__fini(&data[i - 1]);
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
process_msgs__srv__GetScene_Response__Sequence__fini(process_msgs__srv__GetScene_Response__Sequence * array)
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
      process_msgs__srv__GetScene_Response__fini(&array->data[i]);
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

process_msgs__srv__GetScene_Response__Sequence *
process_msgs__srv__GetScene_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Response__Sequence * array = (process_msgs__srv__GetScene_Response__Sequence *)allocator.allocate(sizeof(process_msgs__srv__GetScene_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__srv__GetScene_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__srv__GetScene_Response__Sequence__destroy(process_msgs__srv__GetScene_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__srv__GetScene_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__srv__GetScene_Response__Sequence__are_equal(const process_msgs__srv__GetScene_Response__Sequence * lhs, const process_msgs__srv__GetScene_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__srv__GetScene_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__srv__GetScene_Response__Sequence__copy(
  const process_msgs__srv__GetScene_Response__Sequence * input,
  process_msgs__srv__GetScene_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__srv__GetScene_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__srv__GetScene_Response * data =
      (process_msgs__srv__GetScene_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__srv__GetScene_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__srv__GetScene_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__srv__GetScene_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "process_msgs/srv/detail/get_scene__functions.h"

bool
process_msgs__srv__GetScene_Event__init(process_msgs__srv__GetScene_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    process_msgs__srv__GetScene_Event__fini(msg);
    return false;
  }
  // request
  if (!process_msgs__srv__GetScene_Request__Sequence__init(&msg->request, 0)) {
    process_msgs__srv__GetScene_Event__fini(msg);
    return false;
  }
  // response
  if (!process_msgs__srv__GetScene_Response__Sequence__init(&msg->response, 0)) {
    process_msgs__srv__GetScene_Event__fini(msg);
    return false;
  }
  return true;
}

void
process_msgs__srv__GetScene_Event__fini(process_msgs__srv__GetScene_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  process_msgs__srv__GetScene_Request__Sequence__fini(&msg->request);
  // response
  process_msgs__srv__GetScene_Response__Sequence__fini(&msg->response);
}

bool
process_msgs__srv__GetScene_Event__are_equal(const process_msgs__srv__GetScene_Event * lhs, const process_msgs__srv__GetScene_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!process_msgs__srv__GetScene_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!process_msgs__srv__GetScene_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
process_msgs__srv__GetScene_Event__copy(
  const process_msgs__srv__GetScene_Event * input,
  process_msgs__srv__GetScene_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!process_msgs__srv__GetScene_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!process_msgs__srv__GetScene_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

process_msgs__srv__GetScene_Event *
process_msgs__srv__GetScene_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Event * msg = (process_msgs__srv__GetScene_Event *)allocator.allocate(sizeof(process_msgs__srv__GetScene_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(process_msgs__srv__GetScene_Event));
  bool success = process_msgs__srv__GetScene_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
process_msgs__srv__GetScene_Event__destroy(process_msgs__srv__GetScene_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    process_msgs__srv__GetScene_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
process_msgs__srv__GetScene_Event__Sequence__init(process_msgs__srv__GetScene_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Event * data = NULL;

  if (size) {
    data = (process_msgs__srv__GetScene_Event *)allocator.zero_allocate(size, sizeof(process_msgs__srv__GetScene_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = process_msgs__srv__GetScene_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        process_msgs__srv__GetScene_Event__fini(&data[i - 1]);
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
process_msgs__srv__GetScene_Event__Sequence__fini(process_msgs__srv__GetScene_Event__Sequence * array)
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
      process_msgs__srv__GetScene_Event__fini(&array->data[i]);
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

process_msgs__srv__GetScene_Event__Sequence *
process_msgs__srv__GetScene_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  process_msgs__srv__GetScene_Event__Sequence * array = (process_msgs__srv__GetScene_Event__Sequence *)allocator.allocate(sizeof(process_msgs__srv__GetScene_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = process_msgs__srv__GetScene_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
process_msgs__srv__GetScene_Event__Sequence__destroy(process_msgs__srv__GetScene_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    process_msgs__srv__GetScene_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
process_msgs__srv__GetScene_Event__Sequence__are_equal(const process_msgs__srv__GetScene_Event__Sequence * lhs, const process_msgs__srv__GetScene_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!process_msgs__srv__GetScene_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
process_msgs__srv__GetScene_Event__Sequence__copy(
  const process_msgs__srv__GetScene_Event__Sequence * input,
  process_msgs__srv__GetScene_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(process_msgs__srv__GetScene_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    process_msgs__srv__GetScene_Event * data =
      (process_msgs__srv__GetScene_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!process_msgs__srv__GetScene_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          process_msgs__srv__GetScene_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!process_msgs__srv__GetScene_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
