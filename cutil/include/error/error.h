#ifndef CUTIL_ERROR_ERROR_H
#define CUTIL_ERROR_ERROR_H

#include "status.h"
#include "string/declare.h"

int is_error(enum ErrorStatus const status);

struct Error_t;
struct ErrorMethods;

typedef struct Error {
    struct Error_t* self;
    struct ErrorMethods const*const methods;
} Error;

struct ErrorMethods {
    String (*error)(struct Error_t*const self);
    Error* (*cause)(struct Error_t*const self);
    Error (*destroy)(struct Error_t*const self);
};

#endif
