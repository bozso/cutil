#ifndef CUTIL_MEMORY_ARRAY_H
#define CUTIL_MEMORY_ARRAY_H

#include <stdint.h>
#include "allocator.h"
#include "drop.h"

typedef size_t byte;

typedef struct ArrayMeta {
    Allocator* allocator;
    byte element_size;
} ArrayMeta;

typedef struct Array {
    ArrayMeta const* meta;
    void* data;
    uint64_t length;
    uint64_t capacity;
} Array;

ErrorStatus array_with_capacity(Array*const self ,ArrayMeta const*const meta, uint64_t capacity);
ErrorStatus array_resize(Array*const self, uint64_t nelem);

typedef struct ArrayMetaMethods {
    cutil_memory_drop drop;
} ArrayMetaMethods;

ArrayMetaMethods const*const array_meta_methods(void);

#endif
