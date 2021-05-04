#include "interface.h"

ErrorStatus refcount_decref(ReferenceCounter*const self)
{
    if (self->methods->decref(self) == 0) {
        return self->methods->drop(self);
    }
    return ErrorOk;
}

ReferenceCounter as_reference_counted(
    void*const rc,
    ReferenceCounterMethods const*const methods
)
{
    return (ReferenceCounter) {
        .self = rc,
        .methods = methods,
    };
}
