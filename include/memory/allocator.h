#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include "error/error.h"
#include <stddef.h>

struct Allocator_t;

struct AllocatorMethods {
    void* (*allocate)(struct Allocator_t* const, size_t const, Error*);
    void* (*reallocate)(struct Allocator_t* const, void* ptr, size_t const,
                        Error*);
    void (*deallocate)(struct Allocator_t* const, void* const);
};

struct Allocator {
    struct Allocator_t* self;
    struct AllocatorMethods const* const methods;
};

void* allocate_impl(struct Allocator* const self, size_t const size, Error*);
void* reallocate_impl(struct Allocator* const self, void* ptr,
                      size_t const size, Error*);
void deallocate(struct Allocator* const self, void* const ptr);

#define allocate(alloc, TYPE, size)                                           \
    (TYPE*)allocate_impl(alloc, sizeof(TYPE) * size)

struct Allocator init_allocator_with_errors(struct Allocator* const allocator);

#endif
