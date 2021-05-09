#include "memory/allocator.h"
#include "error/error.h"

void* allocate_impl(struct Allocator* const self, size_t const size,
                    Error* err) {
    return self->methods->allocate(self->self, size, err);
}

void* reallocate_impl(struct Allocator* const self, void* ptr,
                      size_t const size, Error* err) {
    return self->methods->reallocate(self->self, ptr, size, err);
}

void deallocate(struct Allocator* const self, void* const ptr) {
    return self->methods->deallocate(self->self, ptr);
}
