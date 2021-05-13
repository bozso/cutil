#ifdef CUTIL_OPENMP
#include <omp.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/panic.h"

static void default_panicf_impl(struct FileContext const fc,
                                char const* const fmt, va_list args) {
    /// TODO: check ret?
    fprintf(stderr, "Panic -- File: '%s'; Line: %d.", fc.name, fc.line);

    fprintf(stderr, " ");
    vfprintf(stderr, fmt, args);
    exit(1);
}

static panic_fn fn_impl = default_panicf_impl;

void set_panicf_handler(panic_fn fn) {
#ifdef CUTIL_OPENMP
    omp_lock_t lock;
    omp_init_lock(&lock);
    omp_set_lock(&lock);
#endif
    fn_impl = fn;
#ifdef CUTIL_OPENMP
    omp_unset_lock(&lock);
    omp_destroy_lock(&lock);
#endif
}

void panicf_impl(struct FileContext const fc, char const* const fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fn_impl(fc, fmt, args);
    va_end(args);
}
