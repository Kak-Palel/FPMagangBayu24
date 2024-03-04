// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__STRUCT_HPP_
#define ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__arm_interfaces__msg__ServoParameters __attribute__((deprecated))
#else
# define DEPRECATED__arm_interfaces__msg__ServoParameters __declspec(deprecated)
#endif

namespace arm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoParameters_
{
  using Type = ServoParameters_<ContainerAllocator>;

  explicit ServoParameters_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->take1 = 0ul;
      this->take2 = 0ul;
      this->take3 = 0ul;
      this->take4 = 0ul;
      this->drop1 = 0ul;
      this->drop2 = 0ul;
      this->drop3 = 0ul;
      this->drop4 = 0ul;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->take1 = 0ul;
      this->take2 = 0ul;
      this->take3 = 0ul;
      this->take4 = 0ul;
      this->drop1 = 0ul;
      this->drop2 = 0ul;
      this->drop3 = 0ul;
      this->drop4 = 0ul;
    }
  }

  explicit ServoParameters_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->take1 = 0ul;
      this->take2 = 0ul;
      this->take3 = 0ul;
      this->take4 = 0ul;
      this->drop1 = 0ul;
      this->drop2 = 0ul;
      this->drop3 = 0ul;
      this->drop4 = 0ul;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->take1 = 0ul;
      this->take2 = 0ul;
      this->take3 = 0ul;
      this->take4 = 0ul;
      this->drop1 = 0ul;
      this->drop2 = 0ul;
      this->drop3 = 0ul;
      this->drop4 = 0ul;
    }
  }

  // field types and members
  using _take1_type =
    uint32_t;
  _take1_type take1;
  using _take2_type =
    uint32_t;
  _take2_type take2;
  using _take3_type =
    uint32_t;
  _take3_type take3;
  using _take4_type =
    uint32_t;
  _take4_type take4;
  using _drop1_type =
    uint32_t;
  _drop1_type drop1;
  using _drop2_type =
    uint32_t;
  _drop2_type drop2;
  using _drop3_type =
    uint32_t;
  _drop3_type drop3;
  using _drop4_type =
    uint32_t;
  _drop4_type drop4;

  // setters for named parameter idiom
  Type & set__take1(
    const uint32_t & _arg)
  {
    this->take1 = _arg;
    return *this;
  }
  Type & set__take2(
    const uint32_t & _arg)
  {
    this->take2 = _arg;
    return *this;
  }
  Type & set__take3(
    const uint32_t & _arg)
  {
    this->take3 = _arg;
    return *this;
  }
  Type & set__take4(
    const uint32_t & _arg)
  {
    this->take4 = _arg;
    return *this;
  }
  Type & set__drop1(
    const uint32_t & _arg)
  {
    this->drop1 = _arg;
    return *this;
  }
  Type & set__drop2(
    const uint32_t & _arg)
  {
    this->drop2 = _arg;
    return *this;
  }
  Type & set__drop3(
    const uint32_t & _arg)
  {
    this->drop3 = _arg;
    return *this;
  }
  Type & set__drop4(
    const uint32_t & _arg)
  {
    this->drop4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arm_interfaces::msg::ServoParameters_<ContainerAllocator> *;
  using ConstRawPtr =
    const arm_interfaces::msg::ServoParameters_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arm_interfaces::msg::ServoParameters_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arm_interfaces::msg::ServoParameters_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arm_interfaces__msg__ServoParameters
    std::shared_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arm_interfaces__msg__ServoParameters
    std::shared_ptr<arm_interfaces::msg::ServoParameters_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoParameters_ & other) const
  {
    if (this->take1 != other.take1) {
      return false;
    }
    if (this->take2 != other.take2) {
      return false;
    }
    if (this->take3 != other.take3) {
      return false;
    }
    if (this->take4 != other.take4) {
      return false;
    }
    if (this->drop1 != other.drop1) {
      return false;
    }
    if (this->drop2 != other.drop2) {
      return false;
    }
    if (this->drop3 != other.drop3) {
      return false;
    }
    if (this->drop4 != other.drop4) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoParameters_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoParameters_

// alias to use template instance with default allocator
using ServoParameters =
  arm_interfaces::msg::ServoParameters_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace arm_interfaces

#endif  // ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__STRUCT_HPP_
