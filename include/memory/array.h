#ifndef CUTIL_ARRAY_ARRAY_H
#define CUTIL_ARRAY_ARRAY_H

#include <stddef.h>
#include <stdint.h>

#include "error/error.h"
#include "result/error.h"

typedef uint64_t array_size;

struct ArrayConfig {
    struct Allocator* allocator;
    array_size default_cap;
};

struct Array {
    struct ArrayConfig const* config;
    array_size len, cap;
    size_t type_size;
    void* buffer;
};

Error array_init_impl(struct Array* const, struct ArrayConfig* const,
                      size_t const, size_t const);

#define array_init(T, arr, conf, cap)                                         \
    array_init_impl((arr), (conf), sizeof(T), cap)

#define array_default_init(T, arr, conf)                                      \
    array_init_impl((arr), (conf), sizeof(T), conf.default_cap)

#endif
