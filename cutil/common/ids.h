#ifndef H_CUTIL_COMMON_IDS
#define H_CUTIL_COMMON_IDS

#include "array_meta.h"

typedef int ID;

typedef struct IDs {
    ArrayMeta meta;
    ID array[MAX_COMPONENTS];
} IDs;

IDs cm_new_ids(void);
ID cm_ids_idx(IDs const*const self, int const idx);

#endif
