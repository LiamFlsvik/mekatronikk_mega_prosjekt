// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:srv/GetScene.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/srv/get_scene.hpp"


#ifndef PROCESS_MSGS__SRV__DETAIL__GET_SCENE__BUILDER_HPP_
#define PROCESS_MSGS__SRV__DETAIL__GET_SCENE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/srv/detail/get_scene__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::srv::GetScene_Request>()
{
  return ::process_msgs::srv::GetScene_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace process_msgs


namespace process_msgs
{

namespace srv
{

namespace builder
{

class Init_GetScene_Response_scene
{
public:
  Init_GetScene_Response_scene()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::process_msgs::srv::GetScene_Response scene(::process_msgs::srv::GetScene_Response::_scene_type arg)
  {
    msg_.scene = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::srv::GetScene_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::srv::GetScene_Response>()
{
  return process_msgs::srv::builder::Init_GetScene_Response_scene();
}

}  // namespace process_msgs


namespace process_msgs
{

namespace srv
{

namespace builder
{

class Init_GetScene_Event_response
{
public:
  explicit Init_GetScene_Event_response(::process_msgs::srv::GetScene_Event & msg)
  : msg_(msg)
  {}
  ::process_msgs::srv::GetScene_Event response(::process_msgs::srv::GetScene_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::srv::GetScene_Event msg_;
};

class Init_GetScene_Event_request
{
public:
  explicit Init_GetScene_Event_request(::process_msgs::srv::GetScene_Event & msg)
  : msg_(msg)
  {}
  Init_GetScene_Event_response request(::process_msgs::srv::GetScene_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetScene_Event_response(msg_);
  }

private:
  ::process_msgs::srv::GetScene_Event msg_;
};

class Init_GetScene_Event_info
{
public:
  Init_GetScene_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetScene_Event_request info(::process_msgs::srv::GetScene_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetScene_Event_request(msg_);
  }

private:
  ::process_msgs::srv::GetScene_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::srv::GetScene_Event>()
{
  return process_msgs::srv::builder::Init_GetScene_Event_info();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__SRV__DETAIL__GET_SCENE__BUILDER_HPP_
