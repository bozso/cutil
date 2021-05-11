#ifndef CUTIL_ARRAY_ARRAY_H
#define CUTIL_ARRAY_ARRAY_H

#include <stdint.h>

#include "error/error.h"
#include "result/error.h"

typedef uint64_t array_size;

struct ArrayConfig {
    struct Allocator* allocator;
    array_size default_cap;
};

struct ArrayMeta {
    struct ArrayConfig* const alloc;
    array_size len, cap;
};

struct Array {
    struct ArrayMeta meta;
    void* buffer;
};

Error array_init(struct Array* const, struct ArrayConfig* const,
                 struct ErrorService* const);

Error array_allocate(struct ArrayConfig const* const, struct ArrayMeta* const,
                     void*, struct ErrorService* const);

#endif
