#include <stdlib.h>

#include "allocators.h"

static void* malloc_allocate(void*const self_, size_t const size)
{
    return malloc(size);
}

static void* malloc_reallocate(void*const self_, void* ptr, size_t const size)
{
    return realloc(ptr, size);
}

static void malloc_deallocate(void*const self_, void*const ptr)
{
    free(ptr);
}

static Allocator const mallocator = {
    .allocator = NULL,
    .allocate = malloc_allocate,
    .reallocate = malloc_reallocate,
    .deallocate = malloc_deallocate,
};

Allocator const*const get_allocator(AllocatorType const type)
{
    switch (type) {
    case AllocatorMallocator:
        return &mallocator;
    default:
        return NULL;
    }
}
