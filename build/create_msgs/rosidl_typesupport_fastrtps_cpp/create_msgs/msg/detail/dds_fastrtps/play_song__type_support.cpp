// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from create_msgs:msg/PlaySong.idl
// generated code does not contain a copyright notice
#include "create_msgs/msg/detail/play_song__rosidl_typesupport_fastrtps_cpp.hpp"
#include "create_msgs/msg/detail/play_song__struct.hpp"

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

namespace create_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
cdr_serialize(
  const create_msgs::msg::PlaySong & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: song
  cdr << ros_message.song;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  create_msgs::msg::PlaySong & ros_message)
{
  // Member: song
  cdr >> ros_message.song;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
get_serialized_size(
  const create_msgs::msg::PlaySong & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: song
  {
    size_t item_size = sizeof(ros_message.song);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_create_msgs
max_serialized_size_PlaySong(
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


  // Member: song
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
    using DataType = create_msgs::msg::PlaySong;
    is_plain =
      (
      offsetof(DataType, song) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PlaySong__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const create_msgs::msg::PlaySong *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PlaySong__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<create_msgs::msg::PlaySong *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PlaySong__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const create_msgs::msg::PlaySong *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PlaySong__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PlaySong(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PlaySong__callbacks = {
  "create_msgs::msg",
  "PlaySong",
  _PlaySong__cdr_serialize,
  _PlaySong__cdr_deserialize,
  _PlaySong__get_serialized_size,
  _PlaySong__max_serialized_size
};

static rosidl_message_type_support_t _PlaySong__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PlaySong__callbacks,
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
get_message_type_support_handle<create_msgs::msg::PlaySong>()
{
  return &create_msgs::msg::typesupport_fastrtps_cpp::_PlaySong__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, create_msgs, msg, PlaySong)() {
  return &create_msgs::msg::typesupport_fastrtps_cpp::_PlaySong__handle;
}

#ifdef __cplusplus
}
#endif
