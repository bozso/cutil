#include <errno.h>

#include "error/error.h"
#include "result/error.h"

bool is_error(Error const err) { return err.tag != ErrorNone; }

ErrorTag error_tag(Error const err) { return err.tag; }

Error error_code(void) {
    Error e;
    e.tag = ErrorCode;
    e.data.code = errno;

    return e;
}

Error error_from_id(result_id const id) {
    Error e;
    e.tag = ErrorID;
    e.data.id = id;

    return e;
}

Error error_ok(void) {
    Error e;
    e.tag = ErrorNone;

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
