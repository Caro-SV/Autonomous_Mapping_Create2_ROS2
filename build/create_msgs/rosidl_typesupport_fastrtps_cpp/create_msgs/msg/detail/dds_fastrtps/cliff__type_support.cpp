// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from create_msgs:msg/Cliff.idl
// generated code does not contain a copyright notice
#include "create_msgs/msg/detail/cliff__rosidl_typesupport_fastrtps_cpp.hpp"
#include "create_msgs/msg/detail/cliff__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace create_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
cdr_serialize(
  const create_msgs::msg::Cliff & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: is_cliff_left
  cdr << (ros_message.is_cliff_left ? true : false);
  // Member: is_cliff_front_left
  cdr << (ros_message.is_cliff_front_left ? true : false);
  // Member: is_cliff_right
  cdr << (ros_message.is_cliff_right ? true : false);
  // Member: is_cliff_front_right
  cdr << (ros_message.is_cliff_front_right ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  create_msgs::msg::Cliff & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: is_cliff_left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_cliff_left = tmp ? true : false;
  }

  // Member: is_cliff_front_left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_cliff_front_left = tmp ? true : false;
  }

  // Member: is_cliff_right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_cliff_right = tmp ? true : false;
  }

  // Member: is_cliff_front_right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_cliff_front_right = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
get_serialized_size(
  const create_msgs::msg::Cliff & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: is_cliff_left
  {
    size_t item_size = sizeof(ros_message.is_cliff_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_cliff_front_left
  {
    size_t item_size = sizeof(ros_message.is_cliff_front_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_cliff_right
  {
    size_t item_size = sizeof(ros_message.is_cliff_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_cliff_front_right
  {
    size_t item_size = sizeof(ros_message.is_cliff_front_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
max_serialized_size_Cliff(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: is_cliff_left
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_cliff_front_left
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_cliff_right
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_cliff_front_right
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = create_msgs::msg::Cliff;
    is_plain =
      (
      offsetof(DataType, is_cliff_front_right) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Cliff__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const create_msgs::msg::Cliff *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Cliff__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<create_msgs::msg::Cliff *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Cliff__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const create_msgs::msg::Cliff *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Cliff__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Cliff(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Cliff__callbacks = {
  "create_msgs::msg",
  "Cliff",
  _Cliff__cdr_serialize,
  _Cliff__cdr_deserialize,
  _Cliff__get_serialized_size,
  _Cliff__max_serialized_size
};

static rosidl_message_type_support_t _Cliff__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Cliff__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace create_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_create_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<create_msgs::msg::Cliff>()
{
  return &create_msgs::msg::typesupport_fastrtps_cpp::_Cliff__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, create_msgs, msg, Cliff)() {
  return &create_msgs::msg::typesupport_fastrtps_cpp::_Cliff__handle;
}

#ifdef __cplusplus
}
#endif
