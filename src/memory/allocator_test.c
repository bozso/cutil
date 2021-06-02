#include "common/panic.h"
#include "memory/allocator.h"
#include "result/result.h"

enum { kb = 1024, mb = kb * 1024, gb = 1024 * mb };

void test_allocator(void) {
    Allocator alloc = mallocator();

    Error err = error_ok();
    void* ptr = allocate_err(&alloc, sizeof(char) * 100, &err);
    error_do_check(err, {
        panicf("expected succesful allocation, got error code: %d",
               error_get_code(err));
    });

    deallocate(&alloc, ptr);

    ptr = allocate_err(&alloc, sizeof(char) * gb * 1, &err);

    if (!is_error(err)) {
        panicf("expected to exceed memory limits");
        deallocate(&alloc, ptr);
    }
}
