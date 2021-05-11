#ifndef CUTIL_MEMORY_DROP_H
#define CUTIL_MEMORY_DROP_H

#include "error/error.h"

typedef Error (*drop_fn)(void* const);

#if !defined(CUTIL_MEMORY_DROP_STACK_SIZE)
#define CUTIL_MEMORY_DROP_STACK_SIZE 100
#endif

struct DropStack {
    void* ptrs[CUTIL_MEMORY_DROP_STACK_SIZE];
    drop_fn droppers[CUTIL_MEMORY_DROP_STACK_SIZE];
};

#endif
