#ifndef CUTIL_MEMORY_MEMORY_H
#define CUTIL_MEMORY_MEMORY_H

#include "error/status.h"
#include "allocator.h"
#include "drop.h"

typedef struct Memory {
    /// Pointer to allocated memory
    void* data;
    /// Pointer to allocator used for allocation and deallocation.
    Allocator* allocator;
} Memory;

/** Initializes Memory struct with an allocated memory region.
 * \param[out] self pointer to struct to be initialied.
 * \param allocator Allocator object.
 * \param size memory size in bytes to allocate.
 * 
 * \return Status of the operation.
 */ 
ErrorStatus memory_allocate(Memory*const self, Allocator*const allocator, size_t const size);

/// Deallocates previously allocated memory.
void memory_deallocate(Memory*const self);


typedef struct MemoryMethods {
    cutil_memory_drop drop;
} MemoryMethods;

MemoryMethods const*const memory_methods(void);

#endif
