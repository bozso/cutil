#include <errno.h>
#include <stddef.h>

#include "result/error.h"
#include "result/result.h"

static void* default_panic_fn = NULL;

bool result_is_error(struct Result const res) { return res.tag != ErrorNone; }
ErrorTag result_error_tag(struct Result const res) { return res.tag; }

Result result_ok(result_id id) {
    struct Result r;
    r.tag = ErrorNone;
    r.data.id = id;

    return r;
}

Result result_from_option(Option const opt) {
    struct Result r;

    if (opt.tag == OptionNone) {
        r.tag = ErrorNone;
    } else {
        r.tag = ErrorID;
        r.data.error.id = opt.id;
    }
    return r;
}

Result result_error_code(void) {
    struct Result r;
    r.tag = ErrorCode;
    r.data.error.code = errno;
    return r;
}

result_id result_unwrap_panic_impl(struct Result const res, void* ptr,
                                   struct FileContext const ctx) {
    // TODO(bozso): implement
    (void)ptr;
    (void)ctx;

    return res.data.id;
}

result_id result_unwrap_impl(struct Result const res,
                             struct FileContext const ctx) {
    return result_unwrap_panic_impl(res, default_panic_fn, ctx);
}

ResultPtr ptr_error_code(void) {
    Error err = error_code();
    return ptr_error(err);
}

Error ptr_to_error(ResultPtr const r) {
    Error e;
    e.tag = r.tag;
    e.data = r.ptr_or_err.error;
    return e;
}

ResultPtr ptr_error(Error const err) {
    ResultPtr r;
    r.tag = err.tag;
    r.ptr_or_err.error = err.data;
    return r;
}

ResultPtr ptr_ok(void* ptr) {
    ResultPtr r;
    r.tag = ErrorNone;
    r.ptr_or_err.ptr = ptr;

    return r;
}
