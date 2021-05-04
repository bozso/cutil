#include "atomic_reference_counted.h"

uint64_t atomic_reference_counted_incref(AtomicReferenceCounted*const self)
{
    atomic_fetch_add(&self->ref_count, 1);
    return atomic_load(&self->ref_count);
}

uint64_t atomic_reference_counted_decref(AtomicReferenceCounted*const self)
{
    atomic_fetch_sub(&self->ref_count, 1);
    return atomic_load(&self->ref_count);
}

static ReferenceCounterMethods atomic_reference_counted_methods_private = {
    .incref = (reference_count_incref)atomic_reference_counted_incref,
    .decref = (reference_count_decref)atomic_reference_counted_decref,
    .drop = (cutil_memory_drop)atomic_reference_counted_drop,
};

ErrorStatus atomic_reference_counted_drop(AtomicReferenceCounted*const self)
{
    return cutil_drop(&self->drop);
}

ReferenceCounterMethods const*const atomic_reference_counted_methods(void)
{
    return &atomic_reference_counted_methods_private;
}

