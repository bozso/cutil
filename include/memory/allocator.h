#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include <stddef.h>

#include "memory/drop.h"
#include "result/result.h"

struct Allocator_t;

typedef void* (*error_allocate_fn)(struct Allocator_t* const, size_t const,
                                   Error*);

typedef void* (*error_reallocate_fn)(struct Allocator_t* const, void*,
                                     size_t const, Error*);

struct AllocatorMethods {
    void* (*allocate)(struct Allocator_t* const, size_t const);
    void* (*reallocate)(struct Allocator_t* const, void* ptr, size_t const);
    void (*deallocate)(struct Allocator_t* const, void* const);
    error_allocate_fn error_allocate;
    error_reallocate_fn error_reallocate;
    drop_fn drop;
};

typedef struct Allocator {
    struct Allocator_t* self;
    struct AllocatorMethods const* const methods;
} Allocator;

void* allocate_impl(Allocator* const, size_t const);
void* reallocate_impl(Allocator* const, void*, size_t const);
void deallocate(Allocator* const self, void* const ptr);

void* allocate_err(Allocator* const, size_t const, Error*);

#define m_allocate(alloc, TYPE, size)                                         \
    allocate_impl((alloc), sizeof(TYPE) * (size))

Allocator init_allocator_with_errors(struct Allocator* const allocator);

Allocator mallocator(void);

#endif
