#ifndef CUTIL_ATOMIC_REFERENCE_COUNTED_H
#define CUTIL_ATOMIC_REFERENCE_COUNTED_H

#include <stdatomic.h>

#include "interface.h"

typedef struct AtomicReferenceCounted {
    void*const obj;
    cutil_drop drop;
    atomic_uint_fast64_t ref_count;
} AtomicReferenceCounted;

uint64_t atomic_reference_counted_incref(AtomicReferenceCounted*const self);
uint64_t atomic_reference_counted_decref(AtomicReferenceCounted*const self);
ErrorStatus atomic_reference_counted_drop(AtomicReferenceCounted*const self);
ReferenceCounterMethods const*const atomic_reference_counted_methods(void);

#endif
