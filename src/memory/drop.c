#include "string.h"

#include "error/error.h"
#include "memory/drop.h"
#include "result/error.h"

static Error drop_stack(void* const ptr, struct ErrorService* const err) {
    struct DropStack* const self = (struct DropStack* const)ptr;

    // TODO(bozso): consider multiple error handling strategies
    for (int ii = 0; ii < CUTIL_MEMORY_DROP_STACK_SIZE; ii++) {
        Error err_ = self->droppers[ii](self->ptrs[ii], err);

        if (is_error(err_)) {
            return err_;
        }
    }

    return error_ok();
}

struct DropStack new_drop_stack(void) {
    struct DropStack ds;

    memset(ds.droppers, 0, sizeof ds.droppers);
    memset(ds.ptrs, 0, sizeof ds.ptrs);
    ds.drop = drop_stack;

    return ds;
}
