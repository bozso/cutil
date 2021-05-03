#ifndef H_CUTIL_COMMON_ERROR
#define H_CUTIL_COMMON_ERROR

#include "types.h"

typedef enum Status {
    StatusOk = 0,
    StatusFail = -100,
    StatusPrintError = -101
} Status;

int is_error(Status const status);

typedef struct Error {
    const_str msg;
    Status status;
} Error;

#endif
