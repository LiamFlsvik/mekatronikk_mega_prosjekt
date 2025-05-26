// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/srv/get_scene.h"


#ifndef PROCESS_MSGS__SRV__DETAIL__GET_SCENE__FUNCTIONS_H_
#define PROCESS_MSGS__SRV__DETAIL__GET_SCENE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "process_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "process_msgs/srv/detail/get_scene__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/GetScene message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * process_msgs__srv__GetScene_Request
 * )) before or use
 * process_msgs__srv__GetScene_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Request__init(process_msgs__srv__GetScene_Request * msg);

/// Finalize srv/GetScene message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Request__fini(process_msgs__srv__GetScene_Request * msg);

/// Create srv/GetScene message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * process_msgs__srv__GetScene_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
process_msgs__srv__GetScene_Request *
process_msgs__srv__GetScene_Request__create(void);

/// Destroy srv/GetScene message.
/**
 * It calls
 * process_msgs__srv__GetScene_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Request__destroy(process_msgs__srv__GetScene_Request * msg);

/// Check for srv/GetScene message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Request__are_equal(const process_msgs__srv__GetScene_Request * lhs, const process_msgs__srv__GetScene_Request * rhs);

/// Copy a srv/GetScene message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Request__copy(
  const process_msgs__srv__GetScene_Request * input,
  process_msgs__srv__GetScene_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/GetScene messages.
/**
 * It allocates the memory for the number of elements and calls
 * process_msgs__srv__GetScene_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Request__Sequence__init(process_msgs__srv__GetScene_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetScene messages.
/**
 * It calls
 * process_msgs__srv__GetScene_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Request__Sequence__fini(process_msgs__srv__GetScene_Request__Sequence * array);

/// Create array of srv/GetScene messages.
/**
 * It allocates the memory for the array and calls
 * process_msgs__srv__GetScene_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
process_msgs__srv__GetScene_Request__Sequence *
process_msgs__srv__GetScene_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetScene messages.
/**
 * It calls
 * process_msgs__srv__GetScene_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Request__Sequence__destroy(process_msgs__srv__GetScene_Request__Sequence * array);

/// Check for srv/GetScene message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Request__Sequence__are_equal(const process_msgs__srv__GetScene_Request__Sequence * lhs, const process_msgs__srv__GetScene_Request__Sequence * rhs);

/// Copy an array of srv/GetScene messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Request__Sequence__copy(
  const process_msgs__srv__GetScene_Request__Sequence * input,
  process_msgs__srv__GetScene_Request__Sequence * output);

/// Initialize srv/GetScene message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * process_msgs__srv__GetScene_Response
 * )) before or use
 * process_msgs__srv__GetScene_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Response__init(process_msgs__srv__GetScene_Response * msg);

/// Finalize srv/GetScene message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Response__fini(process_msgs__srv__GetScene_Response * msg);

/// Create srv/GetScene message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * process_msgs__srv__GetScene_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
process_msgs__srv__GetScene_Response *
process_msgs__srv__GetScene_Response__create(void);

/// Destroy srv/GetScene message.
/**
 * It calls
 * process_msgs__srv__GetScene_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Response__destroy(process_msgs__srv__GetScene_Response * msg);

/// Check for srv/GetScene message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Response__are_equal(const process_msgs__srv__GetScene_Response * lhs, const process_msgs__srv__GetScene_Response * rhs);

/// Copy a srv/GetScene message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Response__copy(
  const process_msgs__srv__GetScene_Response * input,
  process_msgs__srv__GetScene_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/GetScene messages.
/**
 * It allocates the memory for the number of elements and calls
 * process_msgs__srv__GetScene_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Response__Sequence__init(process_msgs__srv__GetScene_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetScene messages.
/**
 * It calls
 * process_msgs__srv__GetScene_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Response__Sequence__fini(process_msgs__srv__GetScene_Response__Sequence * array);

/// Create array of srv/GetScene messages.
/**
 * It allocates the memory for the array and calls
 * process_msgs__srv__GetScene_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
process_msgs__srv__GetScene_Response__Sequence *
process_msgs__srv__GetScene_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetScene messages.
/**
 * It calls
 * process_msgs__srv__GetScene_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Response__Sequence__destroy(process_msgs__srv__GetScene_Response__Sequence * array);

/// Check for srv/GetScene message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Response__Sequence__are_equal(const process_msgs__srv__GetScene_Response__Sequence * lhs, const process_msgs__srv__GetScene_Response__Sequence * rhs);

/// Copy an array of srv/GetScene messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Response__Sequence__copy(
  const process_msgs__srv__GetScene_Response__Sequence * input,
  process_msgs__srv__GetScene_Response__Sequence * output);

/// Initialize srv/GetScene message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * process_msgs__srv__GetScene_Event
 * )) before or use
 * process_msgs__srv__GetScene_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Event__init(process_msgs__srv__GetScene_Event * msg);

/// Finalize srv/GetScene message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Event__fini(process_msgs__srv__GetScene_Event * msg);

/// Create srv/GetScene message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * process_msgs__srv__GetScene_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
process_msgs__srv__GetScene_Event *
process_msgs__srv__GetScene_Event__create(void);

/// Destroy srv/GetScene message.
/**
 * It calls
 * process_msgs__srv__GetScene_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Event__destroy(process_msgs__srv__GetScene_Event * msg);

/// Check for srv/GetScene message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Event__are_equal(const process_msgs__srv__GetScene_Event * lhs, const process_msgs__srv__GetScene_Event * rhs);

/// Copy a srv/GetScene message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Event__copy(
  const process_msgs__srv__GetScene_Event * input,
  process_msgs__srv__GetScene_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_type_hash_t *
process_msgs__srv__GetScene_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeDescription *
process_msgs__srv__GetScene_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource *
process_msgs__srv__GetScene_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
process_msgs__srv__GetScene_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/GetScene messages.
/**
 * It allocates the memory for the number of elements and calls
 * process_msgs__srv__GetScene_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Event__Sequence__init(process_msgs__srv__GetScene_Event__Sequence * array, size_t size);

/// Finalize array of srv/GetScene messages.
/**
 * It calls
 * process_msgs__srv__GetScene_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Event__Sequence__fini(process_msgs__srv__GetScene_Event__Sequence * array);

/// Create array of srv/GetScene messages.
/**
 * It allocates the memory for the array and calls
 * process_msgs__srv__GetScene_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
process_msgs__srv__GetScene_Event__Sequence *
process_msgs__srv__GetScene_Event__Sequence__create(size_t size);

/// Destroy array of srv/GetScene messages.
/**
 * It calls
 * process_msgs__srv__GetScene_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
void
process_msgs__srv__GetScene_Event__Sequence__destroy(process_msgs__srv__GetScene_Event__Sequence * array);

/// Check for srv/GetScene message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Event__Sequence__are_equal(const process_msgs__srv__GetScene_Event__Sequence * lhs, const process_msgs__srv__GetScene_Event__Sequence * rhs);

/// Copy an array of srv/GetScene messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_process_msgs
bool
process_msgs__srv__GetScene_Event__Sequence__copy(
  const process_msgs__srv__GetScene_Event__Sequence * input,
  process_msgs__srv__GetScene_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // PROCESS_MSGS__SRV__DETAIL__GET_SCENE__FUNCTIONS_H_
