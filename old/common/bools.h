#ifndef H_CUTIL_COMMON_BOOLS
#define H_CUTIL_COMMON_BOOLS

#include "array_meta.h"

typedef struct Bools {
    ArrayMeta meta;
    int array[MAX_COMPONENTS];
} Bools;

Bools cm_new_bools(void);

#endif
