// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice
#include "arm_interfaces/msg/detail/posisi_bidak__rosidl_typesupport_fastrtps_cpp.hpp"
#include "arm_interfaces/msg/detail/posisi_bidak__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace arm_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arm_interfaces
cdr_serialize(
  const arm_interfaces::msg::PosisiBidak & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: fromx
  cdr << ros_message.fromx;
  // Member: fromy
  cdr << ros_message.fromy;
  // Member: tox
  cdr << ros_message.tox;
  // Member: toy
  cdr << ros_message.toy;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arm_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  arm_interfaces::msg::PosisiBidak & ros_message)
{
  // Member: fromx
  cdr >> ros_message.fromx;

  // Member: fromy
  cdr >> ros_message.fromy;

  // Member: tox
  cdr >> ros_message.tox;

  // Member: toy
  cdr >> ros_message.toy;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arm_interfaces
get_serialized_size(
  const arm_interfaces::msg::PosisiBidak & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: fromx
  {
    size_t item_size = sizeof(ros_message.fromx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fromy
  {
    size_t item_size = sizeof(ros_message.fromy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tox
  {
    size_t item_size = sizeof(ros_message.tox);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: toy
  {
    size_t item_size = sizeof(ros_message.toy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arm_interfaces
max_serialized_size_PosisiBidak(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: fromx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: fromy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: tox
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: toy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _PosisiBidak__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const arm_interfaces::msg::PosisiBidak *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PosisiBidak__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<arm_interfaces::msg::PosisiBidak *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PosisiBidak__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const arm_interfaces::msg::PosisiBidak *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PosisiBidak__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PosisiBidak(full_bounded, 0);
}

static message_type_support_callbacks_t _PosisiBidak__callbacks = {
  "arm_interfaces::msg",
  "PosisiBidak",
  _PosisiBidak__cdr_serialize,
  _PosisiBidak__cdr_deserialize,
  _PosisiBidak__get_serialized_size,
  _PosisiBidak__max_serialized_size
};

static rosidl_message_type_support_t _PosisiBidak__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PosisiBidak__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace arm_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_arm_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<arm_interfaces::msg::PosisiBidak>()
{
  return &arm_interfaces::msg::typesupport_fastrtps_cpp::_PosisiBidak__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, arm_interfaces, msg, PosisiBidak)() {
  return &arm_interfaces::msg::typesupport_fastrtps_cpp::_PosisiBidak__handle;
}

#ifdef __cplusplus
}
#endif
