#ifndef CUTIL_ARRAY_ARRAY_H
#define CUTIL_ARRAY_ARRAY_H

#include "common.h"
#include "config.h"
#include "meta.h"

struct Array {
    struct ArrayMeta meta;
    void* buffer;
};

Option array_init(struct Array* const, struct ArrayConfig* const,
                  struct ErrorService* const);

void array_allocate(struct ArrayConfig const* const, struct ArrayMeta* const,
                    void* buffer, struct ErrorService*);

#endif
