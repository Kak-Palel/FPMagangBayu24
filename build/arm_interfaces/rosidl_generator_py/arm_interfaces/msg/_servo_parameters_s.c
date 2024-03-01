// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "arm_interfaces/msg/detail/servo_parameters__struct.h"
#include "arm_interfaces/msg/detail/servo_parameters__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool arm_interfaces__msg__servo_parameters__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("arm_interfaces.msg._servo_parameters.ServoParameters", full_classname_dest, 52) == 0);
  }
  arm_interfaces__msg__ServoParameters * ros_message = _ros_message;
  {  // take1
    PyObject * field = PyObject_GetAttrString(_pymsg, "take1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->take1 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // take2
    PyObject * field = PyObject_GetAttrString(_pymsg, "take2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->take2 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // take3
    PyObject * field = PyObject_GetAttrString(_pymsg, "take3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->take3 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // take4
    PyObject * field = PyObject_GetAttrString(_pymsg, "take4");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->take4 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // drop1
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drop1 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // drop2
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drop2 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // drop3
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drop3 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // drop4
    PyObject * field = PyObject_GetAttrString(_pymsg, "drop4");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->drop4 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * arm_interfaces__msg__servo_parameters__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ServoParameters */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("arm_interfaces.msg._servo_parameters");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ServoParameters");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  arm_interfaces__msg__ServoParameters * ros_message = (arm_interfaces__msg__ServoParameters *)raw_ros_message;
  {  // take1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->take1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "take1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // take2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->take2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "take2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // take3
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->take3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "take3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // take4
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->take4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "take4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drop1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->drop1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drop2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->drop2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drop3
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->drop3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drop4
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->drop4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "drop4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
