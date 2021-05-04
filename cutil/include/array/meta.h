#ifndef CUTIL_ARRAY_META_H
#define CUTIL_ARRAY_META_H

#include "config.h"

struct ArrayMeta {
    struct ArrayConfig*const alloc;
    array_size len, cap;
};

#endif
