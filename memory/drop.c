#include "drop.h"

ErrorStatus cutil_drop(Dropper*const self)
{
    return self->drop(self->obj);
}
