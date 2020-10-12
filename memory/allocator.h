#ifndef CUTIL_MEMORY_ALLOCATOR_H
#define CUTIL_MEMORY_ALLOCATOR_H

#include "error/status.h"

typedef void* (*allocate_fn)(void*const, size_t const);
typedef void* (*reallocate_fn)(void*const, void* ptr, size_t const);
typedef void  (*deallocate_fn)(void*const, void*const);

typedef struct Allocator {
    void*const allocator; 
    allocate_fn allocate;
    reallocate_fn reallocate;
    deallocate_fn deallocate;
} Allocator;

void* allocate(Allocator*const self, size_t const size);
void* reallocate(Allocator*const self, void* ptr, size_t const size);
void deallocate(Allocator*const self, void*const ptr);

typedef struct AllocateErrorHandling {
    Allocator* allocator;
    ErrorStatus status;
} AllocateErrorHandling;

Allocator init_allocator_with_errors(AllocateErrorHandling*const self, Allocator*const allocator);


#endif
