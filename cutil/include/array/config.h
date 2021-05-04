#ifndef CUTIL_ARRAY_CONFIG_H
#define CUTIL_ARRAY_CONFIG_H

#include "common.h"
#include "memory/allocator.h"

struct ArrayConfig {
    struct Allocator* alloc;
    array_size default_cap;
};

#endif
