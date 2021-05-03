#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "error.h"

static char const*const default_str_dup(char const*const in) {
    char* out = malloc(strlen(in) + 1);
    out = strcpy(out, in);

    return out;
}

static str_dup_fn str_dup = default_str_dup;

void set_str_dup_fn(str_dup_fn fn) {
    str_dup = fn;
}

struct Error_t {
    char const* msg;
};

static char const*const error(struct Error_t const*const self) {
    return str_dup(self->msg);
}

static void drop(struct Error_t*const self) {
    free((void*)self->msg);
    self->msg = NULL;
}

static struct ErrorMethods const methods = {
    .error = error,
    .drop = drop,
};

struct Error error_format(char const*const fmt, ...) {
    struct Error err;

    va_list args;
    va_start(args, fmt);
    err.self->msg = vsprintf();


    va_end(args);

    err.methods = &methods;
    return err;
}
