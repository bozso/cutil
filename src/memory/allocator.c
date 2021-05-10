#include "error/error.h"
#include "allocator.h"

void* allocate(Allocator*const self, size_t const size)
{
    return self->allocate(self, size);
}

void* reallocate(Allocator*const self, void* ptr, size_t const size)
{
    return self->reallocate(self, ptr, size);
}

void deallocate(Allocator*const self, void*const ptr)
{
    return self->deallocate(self, ptr);
}

static void* allocate_error_handling(AllocateErrorHandling*const self,
                                     size_t const size)
{
    if (is_error(self->status)) {
        return NULL;
    }

    void*const ptr = self->allocator->allocate(self->allocator, size);

    if (ptr == NULL) {
        self->status = ErrorFail;
    }

    return ptr;
}

static void* reallocate_error_handling(AllocateErrorHandling*const self, void* ptr, size_t const size)
{
    if (is_error(self->status)) {
        return NULL;
    }

    ptr = self->allocator->reallocate(self->allocator, ptr, size);

    if (ptr == NULL) {
        self->status = ErrorFail;
    }

    return ptr;
}

static void deallocate_error_handling(AllocateErrorHandling*const self, void*const ptr)
{
    self->allocator->deallocate(self->allocator, ptr);
}

Allocator init_allocator_with_errors(AllocateErrorHandling*const self, Allocator*const allocator)
{
    self->allocator = allocator;
    return (Allocator) {
        .allocator = self,
        .allocate = (allocate_fn)allocate_error_handling,
        .reallocate = (reallocate_fn)reallocate_error_handling,
        .deallocate = (deallocate_fn)deallocate_error_handling,
    };
}
