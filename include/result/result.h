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
    do {                                                                      \
        Result(res) = (x);                                                    \
        if (is_error((res))) {                                                \
            return (res);                                                     \
        }                                                                     \
        while (0)

#define err_check(err)                                                        \
    do {                                                                      \
        if (is_error((err))) {                                                \
            return (err);                                                     \
        }                                                                     \
    } while (0)

#define option_check(opt)                                                     \
    do {                                                                      \
        if ((opt).tag == OptionSome) {                                        \
            return (opt);                                                     \
        }                                                                     \
    } while (0)

#define result_ptr_check(res)                                                 \
    do {                                                                      \
        if ((res).status == StatusError) {                                    \
            Option opt = to_option((res));                                    \
            return opt;                                                       \
        }                                                                     \
    } while (0)

typedef enum OptionTag {
    OptionSome,
    OptionNone,
} OptionTag;

typedef struct Option {
    OptionTag tag;
    result_id id;
} Option;

Option option_some(result_id id);
Option option_none(void);

typedef union PtrOrID {
    void* ptr;
    result_id id;
} PtrOrID;

typedef struct ResultPtr {
    Status status;
    PtrOrID ptr_or_id;
} ResultPtr;

ResultPtr error_ptr(result_id);
ResultPtr ok_ptr(void*);

Option to_option(ResultPtr ptr);

typedef struct ErrorCode {
    OptionTag tag;
    int code;
} ErrorCode;

ErrorCode error_from_code(void);
ErrorCode no_error(void);

#endif
