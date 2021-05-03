#ifndef CUTIL_MEMORY_ALLOCATORS_H
#define CUTIL_MEMORY_ALLOCATORS_H

#include "allocator.h"

typedef enum AllocatorType {
    AllocatorMallocator,
} AllocatorType;

Allocator const*const get_allocator(AllocatorType const type);

#endif
