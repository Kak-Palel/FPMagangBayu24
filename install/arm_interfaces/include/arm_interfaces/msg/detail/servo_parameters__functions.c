// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arm_interfaces:msg/ServoParameters.idl
// generated code does not contain a copyright notice
#include "arm_interfaces/msg/detail/servo_parameters__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
arm_interfaces__msg__ServoParameters__init(arm_interfaces__msg__ServoParameters * msg)
{
  if (!msg) {
    return false;
  }
  // take1
  msg->take1 = 0ul;
  // take2
  msg->take2 = 0ul;
  // take3
  msg->take3 = 0ul;
  // take4
  msg->take4 = 0ul;
  // drop1
  msg->drop1 = 0ul;
  // drop2
  msg->drop2 = 0ul;
  // drop3
  msg->drop3 = 0ul;
  // drop4
  msg->drop4 = 0ul;
  return true;
}

void
arm_interfaces__msg__ServoParameters__fini(arm_interfaces__msg__ServoParameters * msg)
{
  if (!msg) {
    return;
  }
  // take1
  // take2
  // take3
  // take4
  // drop1
  // drop2
  // drop3
  // drop4
}

bool
arm_interfaces__msg__ServoParameters__are_equal(const arm_interfaces__msg__ServoParameters * lhs, const arm_interfaces__msg__ServoParameters * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // take1
  if (lhs->take1 != rhs->take1) {
    return false;
  }
  // take2
  if (lhs->take2 != rhs->take2) {
    return false;
  }
  // take3
  if (lhs->take3 != rhs->take3) {
    return false;
  }
  // take4
  if (lhs->take4 != rhs->take4) {
    return false;
  }
  // drop1
  if (lhs->drop1 != rhs->drop1) {
    return false;
  }
  // drop2
  if (lhs->drop2 != rhs->drop2) {
    return false;
  }
  // drop3
  if (lhs->drop3 != rhs->drop3) {
    return false;
  }
  // drop4
  if (lhs->drop4 != rhs->drop4) {
    return false;
  }
  return true;
}

bool
arm_interfaces__msg__ServoParameters__copy(
  const arm_interfaces__msg__ServoParameters * input,
  arm_interfaces__msg__ServoParameters * output)
{
  if (!input || !output) {
    return false;
  }
  // take1
  output->take1 = input->take1;
  // take2
  output->take2 = input->take2;
  // take3
  output->take3 = input->take3;
  // take4
  output->take4 = input->take4;
  // drop1
  output->drop1 = input->drop1;
  // drop2
  output->drop2 = input->drop2;
  // drop3
  output->drop3 = input->drop3;
  // drop4
  output->drop4 = input->drop4;
  return true;
}

arm_interfaces__msg__ServoParameters *
arm_interfaces__msg__ServoParameters__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_interfaces__msg__ServoParameters * msg = (arm_interfaces__msg__ServoParameters *)allocator.allocate(sizeof(arm_interfaces__msg__ServoParameters), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arm_interfaces__msg__ServoParameters));
  bool success = arm_interfaces__msg__ServoParameters__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arm_interfaces__msg__ServoParameters__destroy(arm_interfaces__msg__ServoParameters * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arm_interfaces__msg__ServoParameters__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arm_interfaces__msg__ServoParameters__Sequence__init(arm_interfaces__msg__ServoParameters__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_interfaces__msg__ServoParameters * data = NULL;

  if (size) {
    data = (arm_interfaces__msg__ServoParameters *)allocator.zero_allocate(size, sizeof(arm_interfaces__msg__ServoParameters), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arm_interfaces__msg__ServoParameters__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arm_interfaces__msg__ServoParameters__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
arm_interfaces__msg__ServoParameters__Sequence__fini(arm_interfaces__msg__ServoParameters__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      arm_interfaces__msg__ServoParameters__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

arm_interfaces__msg__ServoParameters__Sequence *
arm_interfaces__msg__ServoParameters__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_interfaces__msg__ServoParameters__Sequence * array = (arm_interfaces__msg__ServoParameters__Sequence *)allocator.allocate(sizeof(arm_interfaces__msg__ServoParameters__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arm_interfaces__msg__ServoParameters__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arm_interfaces__msg__ServoParameters__Sequence__destroy(arm_interfaces__msg__ServoParameters__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arm_interfaces__msg__ServoParameters__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arm_interfaces__msg__ServoParameters__Sequence__are_equal(const arm_interfaces__msg__ServoParameters__Sequence * lhs, const arm_interfaces__msg__ServoParameters__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arm_interfaces__msg__ServoParameters__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arm_interfaces__msg__ServoParameters__Sequence__copy(
  const arm_interfaces__msg__ServoParameters__Sequence * input,
  arm_interfaces__msg__ServoParameters__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arm_interfaces__msg__ServoParameters);
    arm_interfaces__msg__ServoParameters * data =
      (arm_interfaces__msg__ServoParameters *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arm_interfaces__msg__ServoParameters__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          arm_interfaces__msg__ServoParameters__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arm_interfaces__msg__ServoParameters__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
