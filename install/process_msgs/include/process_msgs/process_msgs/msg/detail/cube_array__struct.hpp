// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from process_msgs:msg/CubeArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/cube_array.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__STRUCT_HPP_
#define PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cubes'
#include "process_msgs/msg/detail/cube__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__process_msgs__msg__CubeArray __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__msg__CubeArray __declspec(deprecated)
#endif

namespace process_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CubeArray_
{
  using Type = CubeArray_<ContainerAllocator>;

  explicit CubeArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit CubeArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _cubes_type =
    std::vector<process_msgs::msg::Cube_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<process_msgs::msg::Cube_<ContainerAllocator>>>;
  _cubes_type cubes;

  // setters for named parameter idiom
  Type & set__cubes(
    const std::vector<process_msgs::msg::Cube_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<process_msgs::msg::Cube_<ContainerAllocator>>> & _arg)
  {
    this->cubes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::msg::CubeArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::msg::CubeArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::msg::CubeArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::msg::CubeArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::CubeArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::CubeArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::CubeArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::CubeArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::msg::CubeArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::msg::CubeArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__msg__CubeArray
    std::shared_ptr<process_msgs::msg::CubeArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__msg__CubeArray
    std::shared_ptr<process_msgs::msg::CubeArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CubeArray_ & other) const
  {
    if (this->cubes != other.cubes) {
      return false;
    }
    return true;
  }
  bool operator!=(const CubeArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CubeArray_

// alias to use template instance with default allocator
using CubeArray =
  process_msgs::msg::CubeArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__CUBE_ARRAY__STRUCT_HPP_
