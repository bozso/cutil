#ifndef CUTIL_MEMORY_DROP_H
#define CUTIL_MEMORY_DROP_H

#include "error/status.h"

typedef ErrorStatus (*cutil_memory_drop)(void*const self);

typedef struct Dropper {
    void*const obj;
    cutil_memory_drop drop;
} Dropper;

ErrorStatus cutil_drop(Dropper*const self);

#endif
