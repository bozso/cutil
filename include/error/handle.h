#ifndef CUTIL_ERROR_HANDLE_H 
#define CUTIL_ERROR_HANDLE_H

typedef struct ErrorHandlerMethods {
} ErrorHandlerMethods;

typedef struct ErrorHandler {
    void*const handler;
    ErrorHandlerMethods const*const methods;
} ErrorService;

#endif
