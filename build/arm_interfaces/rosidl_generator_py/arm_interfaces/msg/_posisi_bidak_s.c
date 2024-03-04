// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from arm_interfaces:msg/PosisiBidak.idl
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
#include "arm_interfaces/msg/detail/posisi_bidak__struct.h"
#include "arm_interfaces/msg/detail/posisi_bidak__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool arm_interfaces__msg__posisi_bidak__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("arm_interfaces.msg._posisi_bidak.PosisiBidak", full_classname_dest, 44) == 0);
  }
  arm_interfaces__msg__PosisiBidak * ros_message = _ros_message;
  {  // fromx
    PyObject * field = PyObject_GetAttrString(_pymsg, "fromx");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fromx = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // fromy
    PyObject * field = PyObject_GetAttrString(_pymsg, "fromy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fromy = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // tox
    PyObject * field = PyObject_GetAttrString(_pymsg, "tox");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tox = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // toy
    PyObject * field = PyObject_GetAttrString(_pymsg, "toy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->toy = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * arm_interfaces__msg__posisi_bidak__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PosisiBidak */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("arm_interfaces.msg._posisi_bidak");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PosisiBidak");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  arm_interfaces__msg__PosisiBidak * ros_message = (arm_interfaces__msg__PosisiBidak *)raw_ros_message;
  {  // fromx
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->fromx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fromx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fromy
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->fromy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fromy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tox
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->tox);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tox", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toy
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->toy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
