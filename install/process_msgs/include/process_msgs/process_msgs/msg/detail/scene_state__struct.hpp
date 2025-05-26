// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/scene_state.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__STRUCT_HPP_
#define PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cubes'
#include "process_msgs/msg/detail/cube_array__struct.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__process_msgs__msg__SceneState __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__msg__SceneState __declspec(deprecated)
#endif

namespace process_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SceneState_
{
  using Type = SceneState_<ContainerAllocator>;

  explicit SceneState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cubes(_init),
    stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cubes_complete = false;
    }
  }

  explicit SceneState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cubes(_alloc, _init),
    stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cubes_complete = false;
    }
  }

  // field types and members
  using _cubes_type =
    process_msgs::msg::CubeArray_<ContainerAllocator>;
  _cubes_type cubes;
  using _cubes_complete_type =
    bool;
  _cubes_complete_type cubes_complete;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__cubes(
    const process_msgs::msg::CubeArray_<ContainerAllocator> & _arg)
  {
    this->cubes = _arg;
    return *this;
  }
  Type & set__cubes_complete(
    const bool & _arg)
  {
    this->cubes_complete = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::msg::SceneState_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::msg::SceneState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::msg::SceneState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::msg::SceneState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::SceneState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::SceneState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::msg::SceneState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::msg::SceneState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::msg::SceneState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::msg::SceneState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__msg__SceneState
    std::shared_ptr<process_msgs::msg::SceneState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__msg__SceneState
    std::shared_ptr<process_msgs::msg::SceneState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SceneState_ & other) const
  {
    if (this->cubes != other.cubes) {
      return false;
    }
    if (this->cubes_complete != other.cubes_complete) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const SceneState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SceneState_

// alias to use template instance with default allocator
using SceneState =
  process_msgs::msg::SceneState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__STRUCT_HPP_
