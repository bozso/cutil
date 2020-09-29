#include "include/common/types.h"
#include "include/common/panic.h"
#include "include/common/array_meta.h"
#include "include/common/ids.h"

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
