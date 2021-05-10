#include "error/error.h"
#include "flecs.h"
#include "memory/allocator.h"

struct ErrorService_t {
    ecs_world_t* ecs;
};

ErrorCode default_error_service(Allocator* const alloc,
                                struct ErrorService* const err) {
    struct ErrorService_t* const ptr =
        allocate(alloc, struct ErrorService_t, 1);

    if (ptr == NULL) {
        return error_from_code();
    }

    err->self = ptr;
    err->self->ecs = ecs_init();

    return no_error();
}
