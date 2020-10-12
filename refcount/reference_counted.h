#ifndef CUTIL_REFERENCE_COUNTED_H
#define CUTIL_REFERENCE_COUNTED_H

#include "interface.h"

typedef struct ReferenceCounted {
    Dropper drop;
    uint64_t ref_count;
} ReferenceCounted;

uint64_t reference_counted_incref(ReferenceCounted*const self);
uint64_t reference_counted_decref(ReferenceCounted*const self);
ErrorStatus reference_counted_drop(ReferenceCounted*const self);
ReferenceCounterMethods const*const reference_counted_methods(void);

#endif
