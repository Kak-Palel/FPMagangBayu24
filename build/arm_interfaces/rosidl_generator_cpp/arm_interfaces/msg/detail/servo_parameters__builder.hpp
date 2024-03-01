// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__BUILDER_HPP_
#define ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__BUILDER_HPP_

#include "arm_interfaces/msg/detail/servo_parameters__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace arm_interfaces
{

namespace msg
{

namespace builder
{

class Init_ServoParameters_drop4
{
public:
  explicit Init_ServoParameters_drop4(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  ::arm_interfaces::msg::ServoParameters drop4(::arm_interfaces::msg::ServoParameters::_drop4_type arg)
  {
    msg_.drop4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_drop3
{
public:
  explicit Init_ServoParameters_drop3(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  Init_ServoParameters_drop4 drop3(::arm_interfaces::msg::ServoParameters::_drop3_type arg)
  {
    msg_.drop3 = std::move(arg);
    return Init_ServoParameters_drop4(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_drop2
{
public:
  explicit Init_ServoParameters_drop2(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  Init_ServoParameters_drop3 drop2(::arm_interfaces::msg::ServoParameters::_drop2_type arg)
  {
    msg_.drop2 = std::move(arg);
    return Init_ServoParameters_drop3(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_drop1
{
public:
  explicit Init_ServoParameters_drop1(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  Init_ServoParameters_drop2 drop1(::arm_interfaces::msg::ServoParameters::_drop1_type arg)
  {
    msg_.drop1 = std::move(arg);
    return Init_ServoParameters_drop2(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_take4
{
public:
  explicit Init_ServoParameters_take4(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  Init_ServoParameters_drop1 take4(::arm_interfaces::msg::ServoParameters::_take4_type arg)
  {
    msg_.take4 = std::move(arg);
    return Init_ServoParameters_drop1(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_take3
{
public:
  explicit Init_ServoParameters_take3(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  Init_ServoParameters_take4 take3(::arm_interfaces::msg::ServoParameters::_take3_type arg)
  {
    msg_.take3 = std::move(arg);
    return Init_ServoParameters_take4(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_take2
{
public:
  explicit Init_ServoParameters_take2(::arm_interfaces::msg::ServoParameters & msg)
  : msg_(msg)
  {}
  Init_ServoParameters_take3 take2(::arm_interfaces::msg::ServoParameters::_take2_type arg)
  {
    msg_.take2 = std::move(arg);
    return Init_ServoParameters_take3(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

class Init_ServoParameters_take1
{
public:
  Init_ServoParameters_take1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoParameters_take2 take1(::arm_interfaces::msg::ServoParameters::_take1_type arg)
  {
    msg_.take1 = std::move(arg);
    return Init_ServoParameters_take2(msg_);
  }

private:
  ::arm_interfaces::msg::ServoParameters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_interfaces::msg::ServoParameters>()
{
  return arm_interfaces::msg::builder::Init_ServoParameters_take1();
}

}  // namespace arm_interfaces

#endif  // ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__BUILDER_HPP_
