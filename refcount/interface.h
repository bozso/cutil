#ifndef CUTIL_REFCOUNT_MEMORY_H
#define CUTIL_REFCOUNT_MEMORY_H

#include <stdint.h>
#include "error/status.h"
#include "memory/drop.h"

typedef uint64_t (*reference_count_incref)(void*const self);
typedef uint64_t (*reference_count_decref)(void*const self);

typedef struct ReferenceCounterMethods {
    reference_count_incref incref;
    reference_count_decref decref;
    cutil_memory_drop drop;
} ReferenceCounterMethods;

typedef struct ReferenceCounter {
    void*const self;
    ReferenceCounterMethods const*const methods;
} ReferenceCounter;

ReferenceCounter as_reference_counted(
    void*const rc,
    ReferenceCounterMethods const*const methods
);

ErrorStatus refcount_decref(ReferenceCounter*const self);

#endif
