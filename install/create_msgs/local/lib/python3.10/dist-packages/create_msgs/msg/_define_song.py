# generated from rosidl_generator_py/resource/_idl.py.em
# with input from create_msgs:msg/DefineSong.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'notes'
# Member 'durations'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DefineSong(type):
    """Metaclass of message 'DefineSong'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('create_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'create_msgs.msg.DefineSong')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__define_song
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__define_song
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__define_song
            cls._TYPE_SUPPORT = module.type_support_msg__msg__define_song
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__define_song

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DefineSong(metaclass=Metaclass_DefineSong):
    """Message class 'DefineSong'."""

    __slots__ = [
        '_song',
        '_length',
        '_notes',
        '_durations',
    ]

    _fields_and_field_types = {
        'song': 'uint8',
        'length': 'uint8',
        'notes': 'sequence<uint8>',
        'durations': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.song = kwargs.get('song', int())
        self.length = kwargs.get('length', int())
        self.notes = array.array('B', kwargs.get('notes', []))
        self.durations = array.array('f', kwargs.get('durations', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.song != other.song:
            return False
        if self.length != other.length:
            return False
        if self.notes != other.notes:
            return False
        if self.durations != other.durations:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def song(self):
        """Message field 'song'."""
        return self._song

    @song.setter
    def song(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'song' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'song' field must be an unsigned integer in [0, 255]"
        self._song = value

    @builtins.property
    def length(self):
        """Message field 'length'."""
        return self._length

    @length.setter
    def length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'length' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'length' field must be an unsigned integer in [0, 255]"
        self._length = value

    @builtins.property
    def notes(self):
        """Message field 'notes'."""
        return self._notes

    @notes.setter
    def notes(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'notes' array.array() must have the type code of 'B'"
            self._notes = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'notes' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._notes = array.array('B', value)

    @builtins.property
    def durations(self):
        """Message field 'durations'."""
        return self._durations

    @durations.setter
    def durations(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'durations' array.array() must have the type code of 'f'"
            self._durations = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'durations' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._durations = array.array('f', value)
