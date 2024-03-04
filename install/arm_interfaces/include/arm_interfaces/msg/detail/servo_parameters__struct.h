// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__STRUCT_H_
#define ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ServoParameters in the package arm_interfaces.
typedef struct arm_interfaces__msg__ServoParameters
{
  uint32_t take1;
  uint32_t take2;
  uint32_t take3;
  uint32_t take4;
  uint32_t drop1;
  uint32_t drop2;
  uint32_t drop3;
  uint32_t drop4;
} arm_interfaces__msg__ServoParameters;

// Struct for a sequence of arm_interfaces__msg__ServoParameters.
typedef struct arm_interfaces__msg__ServoParameters__Sequence
{
  arm_interfaces__msg__ServoParameters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_interfaces__msg__ServoParameters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARM_INTERFACES__MSG__DETAIL__SERVO_PARAMETERS__STRUCT_H_
