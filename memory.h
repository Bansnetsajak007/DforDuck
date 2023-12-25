//will continue tommorow form grow array

#ifndef clox_memory_h
#define clox_memory_h
#include "common.h"

/*
    This macro calculates a new capacity based on a given current capacity. In order
    to get the performance we want, the important part is that it scales based on the
    old size. We grow by a factor of two, which is pretty typical. 1.5× is another
    common choice
*/
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2);

#define GROW_ARRAY(type , pointer , oldCount , newCount) \
    (type*) reallocate(pointer , sizeof(type) * (oldCount), \
    sizeof(type) * (newCount))

#define FREE_ARRAY(type , pointer , oldCount) \
    reallocate(pointer , sizeof(type) * (oldCount), 0)

void* reallocate(void* pointer , size_t oldSize , size_t newSize );

#endif