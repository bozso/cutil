#ifndef CPPUTIL_RESULT_RESULT_H
#define CPPUTIL_RESULT_RESULT_H

#include <stdbool.h>
#include <stdint.h>

typedef uint64_t result_id;

typedef enum Status {
    Ok,
    Error,
} Status;

typedef struct Result {
    Status status;
    result_id id;
} Result;

bool is_error(Result const);

#define TRY(res, x)                                                           \
    Result(res) = (x);                                                        \
    if (is_error((res))) {                                                    \
        return (res);                                                         \
    }

#endif
