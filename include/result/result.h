#ifndef CPPUTIL_RESULT_RESULT_H
#define CPPUTIL_RESULT_RESULT_H

#include <stdbool.h>
#include <stdint.h>

#include "file_context.h"
#include "result/error.h"
#include "result/id.h"
#include "result/option.h"

union ResultUnion {
    union ErrorUnion error;
    result_id id;
};

typedef struct Result {
    ErrorTag tag;
    union ResultUnion data;
} Result;

bool result_is_error(Result const);
ErrorTag result_error_tag(Result const);

Result result_ok(result_id);
Result result_from_option(Option const);
Result result_error_code(void);
result_id result_unwrap_panic_impl(Result const, void*,
                                   struct FileContext const);
result_id result_unwrap_impl(Result const, struct FileContext const);

#define result_unwrap_panic(res, panic)                                       \
    result_unwrap_impl((res), (panic), FILE_CONTEXT)

#define result_unwrap(res) result_unwrap_impl((res), FILE_CONTEXT)

#define TRY(res, x)                                                           \
    do {                                                                      \
        Result(res) = (x);                                                    \
        if (result_is_error((res))) {                                         \
            return (res);                                                     \
        }                                                                     \
        while (0)

#define ERR_CHECK(err)                                                        \
    do {                                                                      \
        if (is_error((err))) {                                                \
            return (err);                                                     \
        }                                                                     \
    } while (0)

#define OPTION_CHECK(opt)                                                     \
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

/**
 * Opaque type that either contains an error code, an error ID or none of them.
 */

union PtrOrID {
    void* ptr;
    result_id id;
} PtrOrID;

typedef struct ResultPtr {
    ErrorTag tag;
    union PtrOrID ptr_or_id;
} ResultPtr;

ResultPtr error_ptr(result_id);
ResultPtr ok_ptr(void*);

Option to_option(ResultPtr ptr);

#endif
