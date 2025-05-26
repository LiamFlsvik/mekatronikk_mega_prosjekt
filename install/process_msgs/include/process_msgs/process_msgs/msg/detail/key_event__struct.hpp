// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from process_msgs:msg/KeyEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/key_event.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__STRUCT_HPP_
#define PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__process_msgs__msg__KeyEvent __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__msg__KeyEvent __declspec(deprecated)
#endif

namespace process_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyEvent_
{
  using Type = KeyEvent_<ContainerAllocator>;

  explicit KeyEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit KeyEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _active_keys_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _active_keys_type active_keys;

  // setters for named parameter idiom
  Type & set__active_keys(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->active_keys = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::msg::KeyEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::msg::KeyEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::KeyEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::KeyEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__msg__KeyEvent
    std::shared_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__msg__KeyEvent
    std::shared_ptr<process_msgs::msg::KeyEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyEvent_ & other) const
  {
    if (this->active_keys != other.active_keys) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyEvent_

// alias to use template instance with default allocator
using KeyEvent =
  process_msgs::msg::KeyEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__KEY_EVENT__STRUCT_HPP_
