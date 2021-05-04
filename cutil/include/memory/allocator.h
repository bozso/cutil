#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include <stddef.h>
#include "error/error.h"

struct Allocator_t;

struct AllocatorMethods {
    Error (*allocate)(void*const, size_t const);
    Error (*reallocate)(void*const, void* ptr, size_t const);
    void  (*deallocate)(void*const, void*const);
};

struct Allocator {
    struct Allocator_t* self;
    struct AllocatorMethods const*const methods;
};

void* allocate_impl(struct Allocator*const self, size_t const size);
void* reallocate_impl(struct Allocator*const self, void* ptr, size_t const size);
void deallocate(struct Allocator*const self, void*const ptr);

#define allocate(alloc, TYPE, size) \
    (TYPE*) allocate_impl(alloc, sizeof(TYPE) * size)


struct Allocator init_allocator_with_errors(
        struct AllocateErrorHandling*const self,
        struct Allocator*const allocator
);

#endif
