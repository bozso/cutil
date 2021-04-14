#ifndef CUTIL_ERROR_HANDLING_H 
#define CUTIL_ERROR_HANDLING_H

enum ErrorTryStatus {
    ErrorTryContinue,
    ErrorTryFinished
};

struct ErrorTry_t;

struct ErrorTryMethods {
    ErrorTryStatus (*error_try)(struct ErrorTry_t*const self, bool const is_error);
    struct Error (*drop)(struct ErrorTry_t*const self);
};

struct ErrorTry {
    struct ErrorTry_t*const self;
    struct ErrorTryMethods*const methods;
};

struct ErrorTry try_n_times(int const times);

#endif
