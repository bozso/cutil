#ifndef CUTIL_ERROR_STATUS_H
#define CUTIL_ERROR_STATUS_H

#if !defined(CUTIL_ERROR_STATUS_FAIL)
#define CUTIL_ERROR_STATUS_FAIL -1000
#endif

typedef enum ErrorStatus {
    ErrorOk,
    ErrorFail = CUTIL_ERROR_STATUS_FAIL,
    ErrorPrint = CUTIL_ERROR_STATUS_FAIL - 1,
} ErrorStatus;

#endif
