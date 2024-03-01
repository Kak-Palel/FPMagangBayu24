// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__BUILDER_HPP_
#define ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__BUILDER_HPP_

#include "arm_interfaces/msg/detail/posisi_bidak__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace arm_interfaces
{

namespace msg
{

namespace builder
{

class Init_PosisiBidak_toy
{
public:
  explicit Init_PosisiBidak_toy(::arm_interfaces::msg::PosisiBidak & msg)
  : msg_(msg)
  {}
  ::arm_interfaces::msg::PosisiBidak toy(::arm_interfaces::msg::PosisiBidak::_toy_type arg)
  {
    msg_.toy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arm_interfaces::msg::PosisiBidak msg_;
};

class Init_PosisiBidak_tox
{
public:
  explicit Init_PosisiBidak_tox(::arm_interfaces::msg::PosisiBidak & msg)
  : msg_(msg)
  {}
  Init_PosisiBidak_toy tox(::arm_interfaces::msg::PosisiBidak::_tox_type arg)
  {
    msg_.tox = std::move(arg);
    return Init_PosisiBidak_toy(msg_);
  }

private:
  ::arm_interfaces::msg::PosisiBidak msg_;
};

class Init_PosisiBidak_fromy
{
public:
  explicit Init_PosisiBidak_fromy(::arm_interfaces::msg::PosisiBidak & msg)
  : msg_(msg)
  {}
  Init_PosisiBidak_tox fromy(::arm_interfaces::msg::PosisiBidak::_fromy_type arg)
  {
    msg_.fromy = std::move(arg);
    return Init_PosisiBidak_tox(msg_);
  }

private:
  ::arm_interfaces::msg::PosisiBidak msg_;
};

class Init_PosisiBidak_fromx
{
public:
  Init_PosisiBidak_fromx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PosisiBidak_fromy fromx(::arm_interfaces::msg::PosisiBidak::_fromx_type arg)
  {
    msg_.fromx = std::move(arg);
    return Init_PosisiBidak_fromy(msg_);
  }

private:
  ::arm_interfaces::msg::PosisiBidak msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arm_interfaces::msg::PosisiBidak>()
{
  return arm_interfaces::msg::builder::Init_PosisiBidak_fromx();
}

}  // namespace arm_interfaces

#endif  // ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__BUILDER_HPP_
