#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include <stddef.h>

#include "error/error.h"
#include "result/result.h"

struct Allocator_t;

struct AllocatorMethods {
    void* (*allocate)(struct Allocator_t* const, size_t const);
    void* (*reallocate)(struct Allocator_t* const, void* ptr, size_t const);
    void (*deallocate)(struct Allocator_t* const, void* const);
};

typedef struct Allocator {
    struct Allocator_t* self;
    struct AllocatorMethods const* const methods;
} Allocator;

void* allocate_impl(Allocator* const, size_t const);
void* reallocate_impl(Allocator* const, void*, size_t const);
void deallocate(Allocator* const self, void* const ptr);

#define allocate(alloc, TYPE, size)                                           \
    allocate_impl((alloc), sizeof(TYPE) * (size))

Allocator init_allocator_with_errors(struct Allocator* const allocator);

#endif
