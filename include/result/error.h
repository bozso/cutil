#ifndef CPPUTIL_RESULT_ERROR_H
#define CPPUTIL_RESULT_ERROR_H

#include <stdbool.h>

#include "result/option.h"

typedef enum ErrorTag {
    ErrorCode,
    ErrorID,
    ErrorNone,
} ErrorTag;

union ErrorUnion {
    int code;
    result_id id;
};

typedef struct Error {
    ErrorTag tag;
    union ErrorUnion data;
} Error;

bool is_error(Error const);
bool error_is_code(int const);
int error_get_code(Error const);
ErrorTag error_tag(Error const);

Error error_code(void);
Error error_from_id(result_id const);
Error error_ok(void);
Error error_from_option(Option const);

#define error_do_check(err, block)                                            \
    do {                                                                      \
        if (is_error((err))) {                                                \
            block                                                             \
        }                                                                     \
    } while (0)

#define error_check_ret(err) error_do_check(err, return err;)

#endif
