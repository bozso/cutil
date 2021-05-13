#include "memory/allocator.h"

void test_allocator(void) {
    Allocator alloc = mallocator();

    m_allocate(&alloc, char, 100);
}
