#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include "error/error.h"
#include "result/result.h"
#include <stddef.h>

struct Allocator_t;

struct AllocatorMethods {
    ResultPtr (*allocate)(struct Allocator_t* const, size_t const,
                          struct ErrorService* const);
    ResultPtr (*reallocate)(struct Allocator_t* const, void* ptr, size_t const,
                            struct ErrorService* const);
    void (*deallocate)(struct Allocator_t* const, void* const);
};

struct Allocator {
    struct Allocator_t* self;
    struct AllocatorMethods const* const methods;
};

void* allocate_impl(struct Allocator* const self, size_t const size,
                    struct ErrorService* const);
void* reallocate_impl(struct Allocator* const self, void* ptr,
                      size_t const size, struct ErrorService* const);
void deallocate(struct Allocator* const self, void* const ptr);

#define allocate(alloc, TYPE, size)                                           \
    (TYPE*)allocate_impl(alloc, sizeof(TYPE) * size)

struct Allocator init_allocator_with_errors(struct Allocator* const allocator);

#endif
