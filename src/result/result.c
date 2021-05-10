#include "result/result.h"
#include <errno.h>
#include <stddef.h>

static void* default_panic_fn = NULL;

union ErrorUnion {
    int code;
    result_id id;
};

struct Error {
    ErrorTag tag;
    union ErrorUnion data;
};

union ResultUnion {
    Error error;
    result_id id;
};

struct Result {
    ErrorTag tag;
    union ResultUnion data;
};

bool is_error(Result const res) { return res.tag != ErrorNone; }
ErrorTag error_tag(Result const res) { return res.tag; }

Result result_ok(result_id id) {
    Result r;
    r.tag = ErrorNone;
    r.data.id = id;

    return r;
}

Result result_from_option(Option const opt) {
    Result r;

    if (opt.tag == OptionNone) {
        r.tag = ErrorNone;
    } else {
        r.tag = ErrorID;
        r.data.error.data.id = opt.id;
    }
    return r;
}

Result result_error_code(void) {
    Result r;
    r.tag = ErrorCode;
    r.data.error.data.code = errno;
    return r;
}

result_id result_unwrap_panic_impl(Result const res, void* ptr,
                                   struct FileContext const ctx) {
    // TODO(bozso): implement
    (void)ptr;
    (void)ctx;

    return res.data.id;
}

result_id result_unwrap_impl(Result const res, struct FileContext const ctx) {
    return result_unwrap_panic_impl(res, default_panic_fn, ctx);
}

Option option_some(result_id id) {
    return (Option){
        .tag = OptionSome,
        .id = id,
    };
}

Option option_none(void) {
    return (Option){
        .tag = OptionNone,
        .id = 0,
    };
}

ResultPtr error_ptr(result_id id) {
    return (ResultPtr){
        .status = StatusError,
        .ptr_or_id = (PtrOrID){.id = id},
    };
}

ResultPtr ok_ptr(void* ptr) {
    return (ResultPtr){
        .status = StatusOk,
        .ptr_or_id = (PtrOrID){.ptr = ptr},
    };
}

Error error_code(void) {
    Error e;
    e.tag = ErrorCode;
    e.data.code = errno;

    return e;
}

Error error_from_result(Result const res) {
    Error e;

    if (res.status == StatusOk) {
        e.tag = ErrorNone;
    } else {
        e.tag = ErrorID;
        e.data.id = res.id;
    }
    return e;
}
