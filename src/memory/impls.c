#include "memory/allocator.h"
#include "result/result.h"

void* allocate_impl(Allocator* const alloc, size_t const size) {
    return alloc->methods->allocate(alloc->self, size);
}

ResultPtr allocate_err(Allocator* const alloc, size_t const size) {
    void* ptr = allocate_impl(alloc, size);

    if (ptr == NULL) {
        return ptr_error_code();
    }

    return ptr_ok(ptr);
}

void deallocate(Allocator* const alloc, void* ptr) {
    alloc->methods->deallocate(alloc->self, ptr);
}
