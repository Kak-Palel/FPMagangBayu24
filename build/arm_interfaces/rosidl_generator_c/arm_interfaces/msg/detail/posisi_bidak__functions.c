// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arm_interfaces:msg/PosisiBidak.idl
// generated code does not contain a copyright notice
#include "arm_interfaces/msg/detail/posisi_bidak__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
arm_interfaces__msg__PosisiBidak__init(arm_interfaces__msg__PosisiBidak * msg)
{
  if (!msg) {
    return false;
  }
  // fromx
  // fromy
  // tox
  // toy
  return true;
}

void
arm_interfaces__msg__PosisiBidak__fini(arm_interfaces__msg__PosisiBidak * msg)
{
  if (!msg) {
    return;
  }
  // fromx
  // fromy
  // tox
  // toy
}

bool
arm_interfaces__msg__PosisiBidak__are_equal(const arm_interfaces__msg__PosisiBidak * lhs, const arm_interfaces__msg__PosisiBidak * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fromx
  if (lhs->fromx != rhs->fromx) {
    return false;
  }
  // fromy
  if (lhs->fromy != rhs->fromy) {
    return false;
  }
  // tox
  if (lhs->tox != rhs->tox) {
    return false;
  }
  // toy
  if (lhs->toy != rhs->toy) {
    return false;
  }
  return true;
}

bool
arm_interfaces__msg__PosisiBidak__copy(
  const arm_interfaces__msg__PosisiBidak * input,
  arm_interfaces__msg__PosisiBidak * output)
{
  if (!input || !output) {
    return false;
  }
  // fromx
  output->fromx = input->fromx;
  // fromy
  output->fromy = input->fromy;
  // tox
  output->tox = input->tox;
  // toy
  output->toy = input->toy;
  return true;
}

arm_interfaces__msg__PosisiBidak *
arm_interfaces__msg__PosisiBidak__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_interfaces__msg__PosisiBidak * msg = (arm_interfaces__msg__PosisiBidak *)allocator.allocate(sizeof(arm_interfaces__msg__PosisiBidak), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arm_interfaces__msg__PosisiBidak));
  bool success = arm_interfaces__msg__PosisiBidak__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arm_interfaces__msg__PosisiBidak__destroy(arm_interfaces__msg__PosisiBidak * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arm_interfaces__msg__PosisiBidak__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arm_interfaces__msg__PosisiBidak__Sequence__init(arm_interfaces__msg__PosisiBidak__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_interfaces__msg__PosisiBidak * data = NULL;

  if (size) {
    data = (arm_interfaces__msg__PosisiBidak *)allocator.zero_allocate(size, sizeof(arm_interfaces__msg__PosisiBidak), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arm_interfaces__msg__PosisiBidak__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arm_interfaces__msg__PosisiBidak__fini(&data[i - 1]);
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
arm_interfaces__msg__PosisiBidak__Sequence__fini(arm_interfaces__msg__PosisiBidak__Sequence * array)
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
      arm_interfaces__msg__PosisiBidak__fini(&array->data[i]);
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

arm_interfaces__msg__PosisiBidak__Sequence *
arm_interfaces__msg__PosisiBidak__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arm_interfaces__msg__PosisiBidak__Sequence * array = (arm_interfaces__msg__PosisiBidak__Sequence *)allocator.allocate(sizeof(arm_interfaces__msg__PosisiBidak__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arm_interfaces__msg__PosisiBidak__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arm_interfaces__msg__PosisiBidak__Sequence__destroy(arm_interfaces__msg__PosisiBidak__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arm_interfaces__msg__PosisiBidak__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arm_interfaces__msg__PosisiBidak__Sequence__are_equal(const arm_interfaces__msg__PosisiBidak__Sequence * lhs, const arm_interfaces__msg__PosisiBidak__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arm_interfaces__msg__PosisiBidak__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arm_interfaces__msg__PosisiBidak__Sequence__copy(
  const arm_interfaces__msg__PosisiBidak__Sequence * input,
  arm_interfaces__msg__PosisiBidak__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arm_interfaces__msg__PosisiBidak);
    arm_interfaces__msg__PosisiBidak * data =
      (arm_interfaces__msg__PosisiBidak *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arm_interfaces__msg__PosisiBidak__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          arm_interfaces__msg__PosisiBidak__fini(&data[i]);
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
    if (!arm_interfaces__msg__PosisiBidak__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
