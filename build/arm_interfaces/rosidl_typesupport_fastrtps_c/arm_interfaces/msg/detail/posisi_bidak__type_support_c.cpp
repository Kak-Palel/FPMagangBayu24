// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice
#include "arm_interfaces/msg/detail/posisi_bidak__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "arm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "arm_interfaces/msg/detail/posisi_bidak__struct.h"
#include "arm_interfaces/msg/detail/posisi_bidak__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PosisiBidak__ros_msg_type = arm_interfaces__msg__PosisiBidak;

static bool _PosisiBidak__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PosisiBidak__ros_msg_type * ros_message = static_cast<const _PosisiBidak__ros_msg_type *>(untyped_ros_message);
  // Field name: fromx
  {
    cdr << ros_message->fromx;
  }

  // Field name: fromy
  {
    cdr << ros_message->fromy;
  }

  // Field name: tox
  {
    cdr << ros_message->tox;
  }

  // Field name: toy
  {
    cdr << ros_message->toy;
  }

  return true;
}

static bool _PosisiBidak__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PosisiBidak__ros_msg_type * ros_message = static_cast<_PosisiBidak__ros_msg_type *>(untyped_ros_message);
  // Field name: fromx
  {
    cdr >> ros_message->fromx;
  }

  // Field name: fromy
  {
    cdr >> ros_message->fromy;
  }

  // Field name: tox
  {
    cdr >> ros_message->tox;
  }

  // Field name: toy
  {
    cdr >> ros_message->toy;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arm_interfaces
size_t get_serialized_size_arm_interfaces__msg__PosisiBidak(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PosisiBidak__ros_msg_type * ros_message = static_cast<const _PosisiBidak__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name fromx
  {
    size_t item_size = sizeof(ros_message->fromx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fromy
  {
    size_t item_size = sizeof(ros_message->fromy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tox
  {
    size_t item_size = sizeof(ros_message->tox);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name toy
  {
    size_t item_size = sizeof(ros_message->toy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PosisiBidak__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_arm_interfaces__msg__PosisiBidak(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arm_interfaces
size_t max_serialized_size_arm_interfaces__msg__PosisiBidak(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: fromx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fromy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: tox
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: toy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _PosisiBidak__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_arm_interfaces__msg__PosisiBidak(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PosisiBidak = {
  "arm_interfaces::msg",
  "PosisiBidak",
  _PosisiBidak__cdr_serialize,
  _PosisiBidak__cdr_deserialize,
  _PosisiBidak__get_serialized_size,
  _PosisiBidak__max_serialized_size
};

static rosidl_message_type_support_t _PosisiBidak__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PosisiBidak,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, arm_interfaces, msg, PosisiBidak)() {
  return &_PosisiBidak__type_support;
}

#if defined(__cplusplus)
}
#endif
