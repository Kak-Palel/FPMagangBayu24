// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice
#include "arm_interfaces/msg/detail/servo_parameters__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "arm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "arm_interfaces/msg/detail/servo_parameters__struct.h"
#include "arm_interfaces/msg/detail/servo_parameters__functions.h"
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


using _ServoParameters__ros_msg_type = arm_interfaces__msg__ServoParameters;

static bool _ServoParameters__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ServoParameters__ros_msg_type * ros_message = static_cast<const _ServoParameters__ros_msg_type *>(untyped_ros_message);
  // Field name: take1
  {
    cdr << ros_message->take1;
  }

  // Field name: take2
  {
    cdr << ros_message->take2;
  }

  // Field name: take3
  {
    cdr << ros_message->take3;
  }

  // Field name: take4
  {
    cdr << ros_message->take4;
  }

  // Field name: drop1
  {
    cdr << ros_message->drop1;
  }

  // Field name: drop2
  {
    cdr << ros_message->drop2;
  }

  // Field name: drop3
  {
    cdr << ros_message->drop3;
  }

  // Field name: drop4
  {
    cdr << ros_message->drop4;
  }

  return true;
}

static bool _ServoParameters__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ServoParameters__ros_msg_type * ros_message = static_cast<_ServoParameters__ros_msg_type *>(untyped_ros_message);
  // Field name: take1
  {
    cdr >> ros_message->take1;
  }

  // Field name: take2
  {
    cdr >> ros_message->take2;
  }

  // Field name: take3
  {
    cdr >> ros_message->take3;
  }

  // Field name: take4
  {
    cdr >> ros_message->take4;
  }

  // Field name: drop1
  {
    cdr >> ros_message->drop1;
  }

  // Field name: drop2
  {
    cdr >> ros_message->drop2;
  }

  // Field name: drop3
  {
    cdr >> ros_message->drop3;
  }

  // Field name: drop4
  {
    cdr >> ros_message->drop4;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arm_interfaces
size_t get_serialized_size_arm_interfaces__msg__ServoParameters(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ServoParameters__ros_msg_type * ros_message = static_cast<const _ServoParameters__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name take1
  {
    size_t item_size = sizeof(ros_message->take1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name take2
  {
    size_t item_size = sizeof(ros_message->take2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name take3
  {
    size_t item_size = sizeof(ros_message->take3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name take4
  {
    size_t item_size = sizeof(ros_message->take4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop1
  {
    size_t item_size = sizeof(ros_message->drop1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop2
  {
    size_t item_size = sizeof(ros_message->drop2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop3
  {
    size_t item_size = sizeof(ros_message->drop3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name drop4
  {
    size_t item_size = sizeof(ros_message->drop4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ServoParameters__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_arm_interfaces__msg__ServoParameters(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arm_interfaces
size_t max_serialized_size_arm_interfaces__msg__ServoParameters(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: take1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: take2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: take3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: take4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: drop1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: drop2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: drop3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: drop4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ServoParameters__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_arm_interfaces__msg__ServoParameters(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ServoParameters = {
  "arm_interfaces::msg",
  "ServoParameters",
  _ServoParameters__cdr_serialize,
  _ServoParameters__cdr_deserialize,
  _ServoParameters__get_serialized_size,
  _ServoParameters__max_serialized_size
};

static rosidl_message_type_support_t _ServoParameters__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ServoParameters,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, arm_interfaces, msg, ServoParameters)() {
  return &_ServoParameters__type_support;
}

#if defined(__cplusplus)
}
#endif
