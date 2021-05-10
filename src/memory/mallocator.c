#include <stdlib.h>

#include "memory/allocator.h"
#include "result/result.h"

static ResultPtr mallocate(struct Allocator_t* const self, size_t const size,
                           struct ErrorService* const err) {
    (void)self;
    void* const ptr = malloc(size);

    if (ptr == NULL) {
        error_ptr(0);
    }

    return ok_ptr(ptr);
}

static struct AllocatorMethods const methods = {
    .allocate = mallocate,
};

Allocator mallocator(void) {
    return (Allocator){
        .self = NULL,
        .methods = &methods,
    };
}
