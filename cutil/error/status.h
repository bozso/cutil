#ifndef CUTIL_ERROR_STATUS_H
#define CUTIL_ERROR_STATUS_H

#if !defined(CUTIL_ERROR_STATUS_FAIL)
#define CUTIL_ERROR_STATUS_FAIL -1000
#endif

#include "cutil/string/like.h"

typedef enum ErrorStatus {
    ErrorOk,
    ErrorFail = CUTIL_ERROR_STATUS_FAIL,
    ErrorPrint = CUTIL_ERROR_STATUS_FAIL - 1,
} ErrorStatus;

typedef struct ErrorMethods {
    String (*error)(void);
    void (*free)(void*const self);
} ErrorMethods;

typedef struct Error {
    void* self;
    ErrorMethods const*const methods;
} Error;



#endif
