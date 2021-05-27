#include "common/panic.h"
#include "memory/allocator.h"
#include "result/result.h"

enum { kb = 1024, mb = kb * 1024, gb = 1024 * mb };

void test_allocator(void) {
    Allocator alloc = mallocator();

    ResultPtr ptr = allocate_err(&alloc, sizeof(char) * 100);
    if (ptr.tag != ErrorNone) {
        panicf("expected succesful allocation, got error code: %d",
               ptr.ptr_or_err.error.code);
    }

    deallocate(&alloc, ptr.ptr_or_err.ptr);

    ptr = allocate_err(&alloc, sizeof(char) * gb * 1);
    if (ptr.tag == ErrorNone) {
        panicf("expected to exceed memory limits");
        deallocate(&alloc, ptr.ptr_or_err.ptr);
    }
}
