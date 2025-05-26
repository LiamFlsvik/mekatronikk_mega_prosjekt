// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from process_msgs:msg/SceneState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "process_msgs/msg/scene_state.hpp"


#ifndef PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__BUILDER_HPP_
#define PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "process_msgs/msg/detail/scene_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace process_msgs
{

namespace msg
{

namespace builder
{

class Init_SceneState_stamp
{
public:
  explicit Init_SceneState_stamp(::process_msgs::msg::SceneState & msg)
  : msg_(msg)
  {}
  ::process_msgs::msg::SceneState stamp(::process_msgs::msg::SceneState::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::process_msgs::msg::SceneState msg_;
};

class Init_SceneState_cubes_complete
{
public:
  explicit Init_SceneState_cubes_complete(::process_msgs::msg::SceneState & msg)
  : msg_(msg)
  {}
  Init_SceneState_stamp cubes_complete(::process_msgs::msg::SceneState::_cubes_complete_type arg)
  {
    msg_.cubes_complete = std::move(arg);
    return Init_SceneState_stamp(msg_);
  }

private:
  ::process_msgs::msg::SceneState msg_;
};

class Init_SceneState_cubes
{
public:
  Init_SceneState_cubes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SceneState_cubes_complete cubes(::process_msgs::msg::SceneState::_cubes_type arg)
  {
    msg_.cubes = std::move(arg);
    return Init_SceneState_cubes_complete(msg_);
  }

private:
  ::process_msgs::msg::SceneState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::process_msgs::msg::SceneState>()
{
  return process_msgs::msg::builder::Init_SceneState_cubes();
}

}  // namespace process_msgs

#endif  // PROCESS_MSGS__MSG__DETAIL__SCENE_STATE__BUILDER_HPP_
