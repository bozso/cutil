#ifndef CUTIL_ERROR_SERVICE_H
#define CUTIL_ERROR_SERVICE_H

#include "flecs.h"
#include "memory/allocator.h"

struct ErrorServiceConfig {
    ecs_world_t* const ecs;
    Allocator* const allocator;
};

struct ErrorServiceConfig default_error_service_config(Allocator* const);

Error create_error_service(struct ErrorServiceConfig const,
                           struct ErrorService* const);

#endif
