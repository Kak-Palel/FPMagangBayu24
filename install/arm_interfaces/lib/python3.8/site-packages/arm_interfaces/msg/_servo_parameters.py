# generated from rosidl_generator_py/resource/_idl.py.em
# with input from arm_interfaces:msg/ServoParameters.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ServoParameters(type):
    """Metaclass of message 'ServoParameters'."""

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
            module = import_type_support('arm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'arm_interfaces.msg.ServoParameters')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__servo_parameters
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__servo_parameters
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__servo_parameters
            cls._TYPE_SUPPORT = module.type_support_msg__msg__servo_parameters
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__servo_parameters

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TAKE1__DEFAULT': 0,
            'TAKE2__DEFAULT': 0,
            'TAKE3__DEFAULT': 0,
            'TAKE4__DEFAULT': 0,
            'DROP1__DEFAULT': 0,
            'DROP2__DEFAULT': 0,
            'DROP3__DEFAULT': 0,
            'DROP4__DEFAULT': 0,
        }

    @property
    def TAKE1__DEFAULT(cls):
        """Return default value for message field 'take1'."""
        return 0

    @property
    def TAKE2__DEFAULT(cls):
        """Return default value for message field 'take2'."""
        return 0

    @property
    def TAKE3__DEFAULT(cls):
        """Return default value for message field 'take3'."""
        return 0

    @property
    def TAKE4__DEFAULT(cls):
        """Return default value for message field 'take4'."""
        return 0

    @property
    def DROP1__DEFAULT(cls):
        """Return default value for message field 'drop1'."""
        return 0

    @property
    def DROP2__DEFAULT(cls):
        """Return default value for message field 'drop2'."""
        return 0

    @property
    def DROP3__DEFAULT(cls):
        """Return default value for message field 'drop3'."""
        return 0

    @property
    def DROP4__DEFAULT(cls):
        """Return default value for message field 'drop4'."""
        return 0


class ServoParameters(metaclass=Metaclass_ServoParameters):
    """Message class 'ServoParameters'."""

    __slots__ = [
        '_take1',
        '_take2',
        '_take3',
        '_take4',
        '_drop1',
        '_drop2',
        '_drop3',
        '_drop4',
    ]

    _fields_and_field_types = {
        'take1': 'uint32',
        'take2': 'uint32',
        'take3': 'uint32',
        'take4': 'uint32',
        'drop1': 'uint32',
        'drop2': 'uint32',
        'drop3': 'uint32',
        'drop4': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.take1 = kwargs.get(
            'take1', ServoParameters.TAKE1__DEFAULT)
        self.take2 = kwargs.get(
            'take2', ServoParameters.TAKE2__DEFAULT)
        self.take3 = kwargs.get(
            'take3', ServoParameters.TAKE3__DEFAULT)
        self.take4 = kwargs.get(
            'take4', ServoParameters.TAKE4__DEFAULT)
        self.drop1 = kwargs.get(
            'drop1', ServoParameters.DROP1__DEFAULT)
        self.drop2 = kwargs.get(
            'drop2', ServoParameters.DROP2__DEFAULT)
        self.drop3 = kwargs.get(
            'drop3', ServoParameters.DROP3__DEFAULT)
        self.drop4 = kwargs.get(
            'drop4', ServoParameters.DROP4__DEFAULT)

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
        if self.take1 != other.take1:
            return False
        if self.take2 != other.take2:
            return False
        if self.take3 != other.take3:
            return False
        if self.take4 != other.take4:
            return False
        if self.drop1 != other.drop1:
            return False
        if self.drop2 != other.drop2:
            return False
        if self.drop3 != other.drop3:
            return False
        if self.drop4 != other.drop4:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def take1(self):
        """Message field 'take1'."""
        return self._take1

    @take1.setter
    def take1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'take1' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'take1' field must be an unsigned integer in [0, 4294967295]"
        self._take1 = value

    @property
    def take2(self):
        """Message field 'take2'."""
        return self._take2

    @take2.setter
    def take2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'take2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'take2' field must be an unsigned integer in [0, 4294967295]"
        self._take2 = value

    @property
    def take3(self):
        """Message field 'take3'."""
        return self._take3

    @take3.setter
    def take3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'take3' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'take3' field must be an unsigned integer in [0, 4294967295]"
        self._take3 = value

    @property
    def take4(self):
        """Message field 'take4'."""
        return self._take4

    @take4.setter
    def take4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'take4' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'take4' field must be an unsigned integer in [0, 4294967295]"
        self._take4 = value

    @property
    def drop1(self):
        """Message field 'drop1'."""
        return self._drop1

    @drop1.setter
    def drop1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drop1' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'drop1' field must be an unsigned integer in [0, 4294967295]"
        self._drop1 = value

    @property
    def drop2(self):
        """Message field 'drop2'."""
        return self._drop2

    @drop2.setter
    def drop2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drop2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'drop2' field must be an unsigned integer in [0, 4294967295]"
        self._drop2 = value

    @property
    def drop3(self):
        """Message field 'drop3'."""
        return self._drop3

    @drop3.setter
    def drop3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drop3' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'drop3' field must be an unsigned integer in [0, 4294967295]"
        self._drop3 = value

    @property
    def drop4(self):
        """Message field 'drop4'."""
        return self._drop4

    @drop4.setter
    def drop4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drop4' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'drop4' field must be an unsigned integer in [0, 4294967295]"
        self._drop4 = value
