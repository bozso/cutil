#include "memory.h"

ErrorStatus memory_allocate(Memory*const self, Allocator*const allocator, size_t const size)
{
    self->data = allocate(allocator, size);
    if (self->data == NULL) {
        return ErrorFail;
    }
    self->allocator = allocator;
    
    return ErrorOk;
}

void memory_deallocate(Memory*const self)
{
    deallocate(self->allocator, self->data);
}

static MemoryMethods const memory_methods_private = {
    .drop = (cutil_memory_drop) memory_deallocate,
};

MemoryMethods const*const memory_methods(void)
{
    return &memory_methods_private;
}
