#include "memory/allocator.h"
#include "result/result.h"

void* allocate_impl(Allocator* const alloc, size_t const size) {
    return alloc->methods->allocate(alloc->self, size);
}

void* reallocate_impl(Allocator* const alloc, void* ptr, size_t const size) {
    return alloc->methods->reallocate(alloc->self, ptr, size);
}

void* allocate_err(Allocator* const alloc, size_t const size, Error* err) {
    error_allocate_fn fn = alloc->methods->error_allocate;

    if (NULL != fn) {
        return fn(alloc->self, size, err);
    }

    void* ptr = allocate_impl(alloc, size);

    if (NULL == ptr) {
        *err = error_code();
    }

    return ptr;
}

void* reallocate_err(Allocator* const alloc, void* ptr, size_t const size,
                     Error* err) {
    error_reallocate_fn fn = alloc->methods->error_reallocate;

    if (NULL != fn) {
        return fn(alloc->self, ptr, size, err);
    }

    ptr = reallocate_impl(alloc, ptr, size);

    if (NULL == ptr) {
        *err = error_code();
    }

    return ptr;
}

void deallocate(Allocator* const alloc, void* ptr) {
    alloc->methods->deallocate(alloc->self, ptr);
}
