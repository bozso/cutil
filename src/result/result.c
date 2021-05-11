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

ResultPtr error_ptr(result_id id) {
    ResultPtr r;
    r.tag = ErrorID;
    r.ptr_or_id.id = id;

    return r;
}

ResultPtr ok_ptr(void* ptr) {
    ResultPtr r;
    r.tag = ErrorID;
    r.ptr_or_id.ptr = ptr;

    return r;
}
