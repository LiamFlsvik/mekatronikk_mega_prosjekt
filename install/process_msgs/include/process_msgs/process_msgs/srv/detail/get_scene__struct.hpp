// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/srv/get_scene.hpp"


#ifndef PROCESS_MSGS__SRV__DETAIL__GET_SCENE__STRUCT_HPP_
#define PROCESS_MSGS__SRV__DETAIL__GET_SCENE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__process_msgs__srv__GetScene_Request __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__srv__GetScene_Request __declspec(deprecated)
#endif

namespace process_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetScene_Request_
{
  using Type = GetScene_Request_<ContainerAllocator>;

  explicit GetScene_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetScene_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::srv::GetScene_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::srv::GetScene_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::srv::GetScene_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::srv::GetScene_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__srv__GetScene_Request
    std::shared_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__srv__GetScene_Request
    std::shared_ptr<process_msgs::srv::GetScene_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetScene_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetScene_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetScene_Request_

// alias to use template instance with default allocator
using GetScene_Request =
  process_msgs::srv::GetScene_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace process_msgs


// Include directives for member types
// Member 'scene'
#include "process_msgs/msg/detail/scene_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__process_msgs__srv__GetScene_Response __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__srv__GetScene_Response __declspec(deprecated)
#endif

namespace process_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetScene_Response_
{
  using Type = GetScene_Response_<ContainerAllocator>;

  explicit GetScene_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : scene(_init)
  {
    (void)_init;
  }

  explicit GetScene_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : scene(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _scene_type =
    process_msgs::msg::SceneState_<ContainerAllocator>;
  _scene_type scene;

  // setters for named parameter idiom
  Type & set__scene(
    const process_msgs::msg::SceneState_<ContainerAllocator> & _arg)
  {
    this->scene = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::srv::GetScene_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::srv::GetScene_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::srv::GetScene_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::srv::GetScene_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__srv__GetScene_Response
    std::shared_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__srv__GetScene_Response
    std::shared_ptr<process_msgs::srv::GetScene_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetScene_Response_ & other) const
  {
    if (this->scene != other.scene) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetScene_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetScene_Response_

// alias to use template instance with default allocator
using GetScene_Response =
  process_msgs::srv::GetScene_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace process_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__process_msgs__srv__GetScene_Event __attribute__((deprecated))
#else
# define DEPRECATED__process_msgs__srv__GetScene_Event __declspec(deprecated)
#endif

namespace process_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetScene_Event_
{
  using Type = GetScene_Event_<ContainerAllocator>;

  explicit GetScene_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetScene_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<process_msgs::srv::GetScene_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<process_msgs::srv::GetScene_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<process_msgs::srv::GetScene_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<process_msgs::srv::GetScene_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<process_msgs::srv::GetScene_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<process_msgs::srv::GetScene_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<process_msgs::srv::GetScene_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<process_msgs::srv::GetScene_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    process_msgs::srv::GetScene_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const process_msgs::srv::GetScene_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      process_msgs::srv::GetScene_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      process_msgs::srv::GetScene_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__process_msgs__srv__GetScene_Event
    std::shared_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__process_msgs__srv__GetScene_Event
    std::shared_ptr<process_msgs::srv::GetScene_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetScene_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetScene_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetScene_Event_

// alias to use template instance with default allocator
using GetScene_Event =
  process_msgs::srv::GetScene_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace process_msgs

namespace process_msgs
{

namespace srv
{

struct GetScene
{
  using Request = process_msgs::srv::GetScene_Request;
  using Response = process_msgs::srv::GetScene_Response;
  using Event = process_msgs::srv::GetScene_Event;
};

}  // namespace srv

}  // namespace process_msgs

#endif  // PROCESS_MSGS__SRV__DETAIL__GET_SCENE__STRUCT_HPP_
