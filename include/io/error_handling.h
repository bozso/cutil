#ifndef CUTIL_IO_ERROR_HANDLING
#define CUTIL_IO_ERROR_HANDLING

typedef struct ErrorHandler {
    void (*handle)(void*const self);
} ErrorHandler;

typedef struct IErrorHandler {
    void* self;
    ErrorHandler* handler;
} IErrorHandler;

#endif
