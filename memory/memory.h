#ifndef CUTIL_MEMORY_MEMORY_H
#define CUTIL_MEMORY_MEMORY_H

#include "error/status.h"
#include "allocator.h"

typedef struct Memory {
    /// Pointer to allocated memory
    void* data;
    /// Pointer to allocator used for allocation and deallocation.
    Allocator* allocator;
} Memory;

ErrorStatus memory_allocate(Memory*const self, Allocator*const allocator, size_t const size);
void memory_deallocate(Memory*const self);

#endif
