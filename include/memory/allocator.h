#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include <stddef.h>
#include "error/error.h"

struct Allocator_t;

struct AllocatorMethods {
    Error (*allocate_fn)(void*const, size_t const);
    Error (*reallocate_fn)(void*const, void* ptr, size_t const);
    void  (*deallocate_fn)(void*const, void*const);
};

struct Allocator {
    struct Allocator_t* self;
    struct AllocatorMethods const*const methods;
} Allocator;

void* allocate(struct Allocator*const self, size_t const size);
void* reallocate(struct Allocator*const self, void* ptr, size_t const size);
void deallocate(struct Allocator*const self, void*const ptr);

struct AllocateErrorHandling {
    struct Allocator* allocator;
    Error* status;
} AllocateErrorHandling;

struct Allocator init_allocator_with_errors(
        struct AllocateErrorHandling*const self,
        struct Allocator*const allocator
);

#endif
