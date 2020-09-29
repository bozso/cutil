#include "include/common/array_meta.h"
#include "include/common/bools.h"

Bools cm_new_bools(void)
{
    return (Bools) {
        .meta = new_array_meta_with_capacity(MAX_COMPONENTS),
        .array = {0},
    };
}
