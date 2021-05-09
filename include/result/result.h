#ifndef CPPUTIL_RESULT_RESULT_H
#define CPPUTIL_RESULT_RESULT_H

#include <stdbool.h>
#include <stdint.h>

typedef uint64_t result_id;

typedef enum Status {
    StatusOk,
    StatusError,
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

typedef enum OptionTag {
    OptionSome,
    OptionNone,
} OptionTag;

typedef struct Option {
    OptionTag tag;
    result_id id;
} Option;

typedef union PtrOrID {
    void* ptr;
    result_id id;
} PtrOrID;

typedef struct ResultPtr {
    Status status;
    PtrOrID ptr_or_id;
} ResultPtr;

Option option_some(result_id id);
Option option_none(void);

#endif
