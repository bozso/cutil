#ifndef CUTIL_MEMORY_MEMORY_H
#define CUTIL_MEMORY_MEMORY_H

#include "allocator.h"

typedef struct Memory {
    void*const data;
    Allocator*const allocator;
} Memory;

Memory memory_allocate(Allocator*const allocator, size_t const size);
Memory memory_deallocate(Memory*const self);

#endif
