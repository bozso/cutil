#include "result/result.h"
#include <errno.h>

bool res_is_error(Result const res) { return res.status == StatusError; }

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

union ErrorUnion {
    int code;
    result_id id;
};

struct Error {
    ErrorTag tag;
    union ErrorUnion data;
};

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

Error error_from_option(Option const opt) {
    Error e;

    if (opt.tag == OptionNone) {
        e.tag = ErrorNone;
    } else {
        e.tag = ErrorID;
        e.data.id = opt.id;
    }
    return e;
}

Error error_ok(void) {
    Error e;
    e.tag = ErrorNone;

    return e;
}

bool is_error(Error const err) { return err.tag != ErrorNone; }
ErrorTag error_tag(Error const err) { return err.tag; }
