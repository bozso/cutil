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

Allocator const mallocator = {
    .allocator = NULL,
    .allocate = malloc_allocate,
    .reallocate = malloc_reallocate,
    .deallocate = malloc_deallocate,
};

typedef struct AllocateErrorHandling {
    Allocator* allocator;
    Status status;
} AllocateErrorHandling;

static void* allocate_error_handling(void*const self_, size_t const size)
{
    AllocateErrorHandling*const self = (AllocateErrorHandling*) self_;
    
    if (is_error(self->status)) {
        return NULL;
    }
    
    void*const ptr = self->allocator->allocate(self->allocator, size);
    
    if (ptr == NULL) {
        self->status = StatusFail;
    }
    
    return ptr;
}

static void* reallocate_error_handling(void*const self_, void* ptr, size_t const size)
{
    AllocateErrorHandling*const self = (AllocateErrorHandling*) self_;
    
    if (is_error(self->status)) {
        return NULL;
    }
    
    ptr = self->allocator->reallocate(self->allocator, ptr, size);
    
    if (ptr == NULL) {
        self->status = StatusFail;
    }
    
    return ptr;
}

static void deallocate_error_handling(void*const self_, void*const ptr)
{
    AllocateErrorHandling const*const self = (AllocateErrorHandling*) self_;
    
    self->allocator->deallocate(self->allocator, ptr);
}

Allocator init_allocator_with_errors(AllocateErrorHandling*const self, Allocator*const allocator)
{
    self->allocator = allocator;
    return (Allocator) {
        .allocator = self,
        .allocate = allocate_error_handling,
        .reallocate = reallocate_error_handling,
        .deallocate = deallocate_error_handling,
    }; 
}
