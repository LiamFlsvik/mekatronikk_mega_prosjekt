// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from process_msgs:msg/Cube.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE__STRUCT_HPP_
#define PROCESS_MSGS__MSG__DETAIL__CUBE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__process_msgs__msg__Cube __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__msg__Cube __declspec(deprecated)
#endif

namespace process_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Cube_
{
  using Type = Cube_<ContainerAllocator>;

  explicit Cube_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = "";
      this->angle = 0.0f;
    }
  }

  explicit Cube_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : color(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = "";
      this->angle = 0.0f;
    }
  }

  // field types and members
  using _color_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _color_type color;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _angle_type =
    float;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__color(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::msg::Cube_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::msg::Cube_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::msg::Cube_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::msg::Cube_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::Cube_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::Cube_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::Cube_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::Cube_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::msg::Cube_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::msg::Cube_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__msg__Cube
    std::shared_ptr<process_msgs::msg::Cube_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__msg__Cube
    std::shared_ptr<process_msgs::msg::Cube_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cube_ & other) const
  {
    if (this->color != other.color) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cube_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cube_

// alias to use template instance with default allocator
using Cube =
  process_msgs::msg::Cube_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE__STRUCT_HPP_
