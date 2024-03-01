// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "arm_interfaces/msg/detail/servo_parameters__rosidl_typesupport_introspection_c.h"
#include "arm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "arm_interfaces/msg/detail/servo_parameters__functions.h"
#include "arm_interfaces/msg/detail/servo_parameters__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  arm_interfaces__msg__ServoParameters__init(message_memory);
}

void ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_fini_function(void * message_memory)
{
  arm_interfaces__msg__ServoParameters__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_member_array[8] = {
  {
    "take1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, take1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "take2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, take2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "take3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, take3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "take4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, take4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drop1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, drop1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drop2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, drop2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drop3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, drop3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drop4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arm_interfaces__msg__ServoParameters, drop4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_members = {
  "arm_interfaces__msg",  // message namespace
  "ServoParameters",  // message name
  8,  // number of fields
  sizeof(arm_interfaces__msg__ServoParameters),
  ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_member_array,  // message members
  ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_type_support_handle = {
  0,
  &ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_arm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, arm_interfaces, msg, ServoParameters)() {
  if (!ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_type_support_handle.typesupport_identifier) {
    ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ServoParameters__rosidl_typesupport_introspection_c__ServoParameters_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
