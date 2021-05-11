#ifndef CUTIL_ERROR_ERROR_H
#define CUTIL_ERROR_ERROR_H

#include "formatter.h"
#include "memory/allocator.h"
#include "result/result.h"
#include "status.h"
#include "string/declare.h"

#include "flecs.h"

struct ErrorService_t;
struct ErrorServiceMethods;

struct ErrorService {
    struct ErrorService_t* self;
    struct ErrorServiceMethods const* const methods;
};

struct ErrorServiceMethods {
    Result (*error)(struct ErrorService_t* const, result_id);
    Option (*format_to)(struct ErrorService_t* const, result_id,
                        struct Formatter* const);
    Option (*cause)(struct ErrorService_t* const, result_id);
    Result (*destroy)(struct ErrorService_t* const self, result_id);
};

struct ErrorServiceConfig {
    ecs_world_t* const ecs;
    Allocator* const allocator;
};

struct ErrorServiceConfig default_error_service_config(Allocator* const);

Error create_error_service(struct ErrorServiceConfig const,
                           struct ErrorService* const);

#endif
