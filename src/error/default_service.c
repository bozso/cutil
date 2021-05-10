#include "error/error.h"
#include "memory/allocator.h"
#include "result/error.h"

struct ErrorService_t {
    ecs_world_t* ecs;
};

Error default_error_service(Allocator* const alloc,
                            struct ErrorService* const err) {
    struct ErrorService_t* const ptr =
        allocate(alloc, struct ErrorService_t, 1);

    if (ptr == NULL) {
        return error_code();
    }

    err->self = ptr;
    err->self->ecs = ecs_init();

    return error_ok();
}
