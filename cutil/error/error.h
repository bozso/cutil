#ifndef CUTIL_ERROR_ERROR_H
#define CUTIL_ERROR_ERROR_H

#include "status.h"
#include "cutil/string/string.h"

int is_error(ErrorStatus const status);

typedef struct ErrorMethods {
    String (*error)(void);
    void (*free)(void*const self);
} ErrorMethods;

typedef struct Error {
    void* self;
    ErrorMethods const*const methods;
} Error;

#endif
