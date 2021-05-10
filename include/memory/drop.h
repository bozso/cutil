#ifndef CUTIL_MEMORY_DROP_H
#define CUTIL_MEMORY_DROP_H

#include "error/error.h"

struct Drop_t;

struct DropMethods {
    Error (*drop)(struct Drop_t* const);
};

struct Drop {
    struct Drop_t* const drop;
    struct DropMethods methods;
};

#if !defined(CUTIL_MEMORY_DROP_STACK_SIZE)
#define CUTIL_MEMORY_DROP_STACK_SIZE 100
#endif

typedef struct DropStack {
    struct Drop droppers[CUTIL_MEMORY_DROP_STACK_SIZE];
} DropStack;

#endif
