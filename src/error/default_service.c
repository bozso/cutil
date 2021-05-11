#include "error/service.h"
#include "memory/allocator.h"
#include "result/error.h"

struct ErrorServiceConfig
default_error_service_config(Allocator* const alloc) {
    return (struct ErrorServiceConfig){
        .ecs = NULL,
        .allocator = alloc,
    };
}

struct ErrorService_t {
    ecs_world_t* ecs;
};

Error create_error_service(struct ErrorServiceConfig const conf,
                           struct ErrorService* const err) {
    struct ErrorService_t* const ptr =
        allocate(conf.allocator, struct ErrorService_t, 1);

    if (ptr == NULL) {
        return error_code();
    }

    ecs_world_t* w = conf.ecs;

    if (w == NULL) {
        w = ecs_init();
    }

    err->self = ptr;
    err->self->ecs = w;

    return error_ok();
}
