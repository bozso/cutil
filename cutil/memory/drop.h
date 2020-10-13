#ifndef CUTIL_MEMORY_DROP_H
#define CUTIL_MEMORY_DROP_H

#include "cutil/error/status.h"

typedef ErrorStatus (*cutil_memory_drop)(void*const self);

typedef struct Dropper {
    void*const obj;
    cutil_memory_drop drop;
} Dropper;

ErrorStatus cutil_drop(Dropper*const self);

#if !defined(CUTIL_MEMORY_DROP_STACK_SIZE)
#define CUTIL_MEMORY_DROP_STACK_SIZE 100
#endif

typedef struct DropStack {
    Dropper droppers[CUTIL_MEMORY_DROP_STACK_SIZE];
} DropStack;

#endif
