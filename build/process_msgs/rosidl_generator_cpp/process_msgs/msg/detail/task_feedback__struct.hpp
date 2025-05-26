// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from process_msgs:msg/TaskFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/task_feedback.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__STRUCT_HPP_
#define PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__process_msgs__msg__TaskFeedback __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__msg__TaskFeedback __declspec(deprecated)
#endif

namespace process_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskFeedback_
{
  using Type = TaskFeedback_<ContainerAllocator>;

  explicit TaskFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->success = false;
      this->message = "";
    }
  }

  explicit TaskFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::msg::TaskFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::msg::TaskFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::TaskFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::TaskFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__msg__TaskFeedback
    std::shared_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__msg__TaskFeedback
    std::shared_ptr<process_msgs::msg::TaskFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskFeedback_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskFeedback_

// alias to use template instance with default allocator
using TaskFeedback =
  process_msgs::msg::TaskFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__TASK_FEEDBACK__STRUCT_HPP_
