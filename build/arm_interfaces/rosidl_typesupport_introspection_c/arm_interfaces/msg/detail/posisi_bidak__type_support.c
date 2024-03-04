// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arm_interfaces/msg/detail/posisi_bidak__rosidl_typesupport_introspection_c.h"
#include "arm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arm_interfaces/msg/detail/posisi_bidak__functions.h"
#include "arm_interfaces/msg/detail/posisi_bidak__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arm_interfaces__msg__PosisiBidak__init(message_memory);
}

void PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_fini_function(void * message_memory)
{
  arm_interfaces__msg__PosisiBidak__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_member_array[4] = {
  {
    "fromx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__PosisiBidak, fromx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fromy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__PosisiBidak, fromy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tox",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__PosisiBidak, tox),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "toy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__PosisiBidak, toy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_members = {
  "arm_interfaces__msg",  // message namespace
  "PosisiBidak",  // message name
  4,  // number of fields
  sizeof(arm_interfaces__msg__PosisiBidak),
  PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_member_array,  // message members
  PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_init_function,  // function to initialize message memory (memory has to be allocated)
  PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_type_support_handle = {
  0,
  &PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_interfaces, msg, PosisiBidak)() {
  if (!PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_type_support_handle.typesupport_identifier) {
    PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PosisiBidak__rosidl_typesupport_introspection_c__PosisiBidak_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
