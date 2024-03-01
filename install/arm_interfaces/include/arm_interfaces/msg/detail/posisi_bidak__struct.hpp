// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__STRUCT_HPP_
#define ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__arm_interfaces__msg__PosisiBidak __attribute__((deprecated))
#else
# define DEPRECATED__arm_interfaces__msg__PosisiBidak __declspec(deprecated)
#endif

namespace arm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PosisiBidak_
{
  using Type = PosisiBidak_<ContainerAllocator>;

  explicit PosisiBidak_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fromx = 0;
      this->fromy = 0;
      this->tox = 0;
      this->toy = 0;
    }
  }

  explicit PosisiBidak_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fromx = 0;
      this->fromy = 0;
      this->tox = 0;
      this->toy = 0;
    }
  }

  // field types and members
  using _fromx_type =
    uint8_t;
  _fromx_type fromx;
  using _fromy_type =
    uint8_t;
  _fromy_type fromy;
  using _tox_type =
    uint8_t;
  _tox_type tox;
  using _toy_type =
    uint8_t;
  _toy_type toy;

  // setters for named parameter idiom
  Type & set__fromx(
    const uint8_t & _arg)
  {
    this->fromx = _arg;
    return *this;
  }
  Type & set__fromy(
    const uint8_t & _arg)
  {
    this->fromy = _arg;
    return *this;
  }
  Type & set__tox(
    const uint8_t & _arg)
  {
    this->tox = _arg;
    return *this;
  }
  Type & set__toy(
    const uint8_t & _arg)
  {
    this->toy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arm_interfaces::msg::PosisiBidak_<ContainerAllocator> *;
  using ConstRawPtr =
    const arm_interfaces::msg::PosisiBidak_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arm_interfaces::msg::PosisiBidak_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arm_interfaces::msg::PosisiBidak_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arm_interfaces__msg__PosisiBidak
    std::shared_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arm_interfaces__msg__PosisiBidak
    std::shared_ptr<arm_interfaces::msg::PosisiBidak_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PosisiBidak_ & other) const
  {
    if (this->fromx != other.fromx) {
      return false;
    }
    if (this->fromy != other.fromy) {
      return false;
    }
    if (this->tox != other.tox) {
      return false;
    }
    if (this->toy != other.toy) {
      return false;
    }
    return true;
  }
  bool operator!=(const PosisiBidak_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PosisiBidak_

// alias to use template instance with default allocator
using PosisiBidak =
  arm_interfaces::msg::PosisiBidak_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace arm_interfaces

#endif  // ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__STRUCT_HPP_
