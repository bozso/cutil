#include "types.h"
#include "panic.h"
#include "array_meta.h"
#include "ids.h"

IDs cm_new_ids(void)
{
    return (IDs) {
        .meta = new_array_meta_with_capacity(MAX_COMPONENTS),
        .array = {0},
    };
}

ID cm_ids_idx(IDs const*const self, int const idx)
{
    array_meta_check_idx_panic(&self->meta, idx);
    return self->array[idx];
}
