// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from process_msgs:msg/SceneState.idl
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
#include "process_msgs/msg/detail/scene_state__struct.h"
#include "process_msgs/msg/detail/scene_state__functions.h"

bool process_msgs__msg__cube_array__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * process_msgs__msg__cube_array__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool process_msgs__msg__scene_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("process_msgs.msg._scene_state.SceneState", full_classname_dest, 40) == 0);
  }
  process_msgs__msg__SceneState * ros_message = _ros_message;
  {  // cubes
    PyObject * field = PyObject_GetAttrString(_pymsg, "cubes");
    if (!field) {
      return false;
    }
    if (!process_msgs__msg__cube_array__convert_from_py(field, &ros_message->cubes)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // cubes_complete
    PyObject * field = PyObject_GetAttrString(_pymsg, "cubes_complete");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->cubes_complete = (Py_True == field);
    Py_DECREF(field);
  }
  {  // stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * process_msgs__msg__scene_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SceneState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("process_msgs.msg._scene_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SceneState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  process_msgs__msg__SceneState * ros_message = (process_msgs__msg__SceneState *)raw_ros_message;
  {  // cubes
    PyObject * field = NULL;
    field = process_msgs__msg__cube_array__convert_to_py(&ros_message->cubes);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cubes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cubes_complete
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->cubes_complete ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cubes_complete", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
