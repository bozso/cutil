#ifndef CUTIL_ARRAY_ARRAY_H
#define CUTIL_ARRAY_ARRAY_H

#include "common.h"
#include "config.h"
#include "meta.h"

void array_allocate(struct ArrayConfig const* const, struct ArrayMeta* const,
                    void* buffer, struct ErrorService*);

#endif
