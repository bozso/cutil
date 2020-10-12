#include "reference_counted.h"

uint64_t reference_counted_incref(ReferenceCounted*const self)
{
    return ++self->ref_count;
}

uint64_t reference_counted_decref(ReferenceCounted*const self)
{
    return --self->ref_count;
}

ErrorStatus reference_counted_drop(ReferenceCounted*const self)
{
    return cutil_drop(&self->drop);
}

static ReferenceCounterMethods reference_counted_methods_private = {
    .incref = (reference_count_incref)reference_counted_incref,
    .decref = (reference_count_decref)reference_counted_decref,
    .drop = (cutil_memory_drop)reference_counted_drop,
};

ReferenceCounterMethods const*const reference_counted_methods(void)
{
    return &reference_counted_methods_private;
}
