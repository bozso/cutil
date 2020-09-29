#include "types.h"
#include "panic.h"
#include "array_meta.h"

ArrayMeta new_array_meta(int const current, int const capacity)
{
    return (ArrayMeta) {
        .current = current,
        .capacity = capacity,
    };
}

ArrayMeta new_array_meta_with_capacity(int const capacity)
{
    return new_array_meta(0, capacity);
}

int array_meta_next_index(ArrayMeta *const self)
{
    int const idx = ++self->current,
              cap = self->capacity;
    if (idx >= cap) {
        panicf("Capacity (%d elements) reached with index %d!\n", cap, idx);
    }
    
    return idx - 1;
}

void array_meta_check_idx_panic(ArrayMeta const*const self, int const idx)
{
    int const curr = self->current;
    if (idx >= curr) {
        panicf("Index %d is out of bounds of limit %d!\n", idx, curr);
    }
}
