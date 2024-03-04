// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice

#ifndef ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__STRUCT_H_
#define ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PosisiBidak in the package arm_interfaces.
typedef struct arm_interfaces__msg__PosisiBidak
{
  int32_t fromx;
  int32_t fromy;
  int32_t tox;
  int32_t toy;
} arm_interfaces__msg__PosisiBidak;

// Struct for a sequence of arm_interfaces__msg__PosisiBidak.
typedef struct arm_interfaces__msg__PosisiBidak__Sequence
{
  arm_interfaces__msg__PosisiBidak * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arm_interfaces__msg__PosisiBidak__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARM_INTERFACES__MSG__DETAIL__POSISI_BIDAK__STRUCT_H_
