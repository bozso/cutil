#include <stdlib.h>

#include "error/error.h"
#include "memory/allocator.h"
#include "result/result.h"

static void* mallocate(struct Allocator_t* const self, size_t const size) {
    (void)self;
    return malloc(size);
}

static void* mreallocate(struct Allocator_t* const self, void* ptr,
                         size_t const size) {
    (void)self;
    return realloc(ptr, size);
}

static void mdeallocate(struct Allocator_t* const self, void* const ptr) {
    (void)self;
    free(ptr);
}

static struct AllocatorMethods const methods = {
    .allocate = mallocate,
    .reallocate = mreallocate,
    .deallocate = mdeallocate,
    .error_allocate = NULL,
    .error_reallocate = NULL,
};

Allocator mallocator(void) {
    return (Allocator){
        .self = NULL,
        .methods = &methods,
    };
}
