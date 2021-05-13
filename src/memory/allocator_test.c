#include "memory/allocator.h"
#include "result/result.h"

void test_allocator(void) {
    Allocator alloc = mallocator();

    ResultPtr ptr = allocate_err(&alloc, sizeof(char) * 100);
    if (ptr.tag != ErrorNone) {
        panicf("expected succesful allocation, got error code: %d",
               ptr.ptr_or_err.error.code);
    }

    deallocate(&alloc, ptr.ptr_or_err.ptr);
}
