// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__TRAITS_HPP_
#define ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__TRAITS_HPP_

#include "arm_interfaces/msg/detail/posisi_bidak__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<arm_interfaces::msg::PosisiBidak>()
{
  return "arm_interfaces::msg::PosisiBidak";
}

template<>
inline const char * name<arm_interfaces::msg::PosisiBidak>()
{
  return "arm_interfaces/msg/PosisiBidak";
}

template<>
struct has_fixed_size<arm_interfaces::msg::PosisiBidak>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<arm_interfaces::msg::PosisiBidak>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<arm_interfaces::msg::PosisiBidak>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__TRAITS_HPP_
