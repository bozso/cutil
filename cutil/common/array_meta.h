#ifndef H_CUTIL_COMMON_ARRAY_META
#define H_CUTIL_COMMON_ARRAY_META

typedef struct ArrayMeta {
    int current;
    int capacity;    
} ArrayMeta; 

#ifndef MAX_COMPONENTS
#define MAX_COMPONENTS 100
#endif

ArrayMeta new_array_meta(int const current, int const capacity);
ArrayMeta new_array_meta_with_capacity(int const capacity);
int array_meta_next_index(ArrayMeta *const self);
void array_meta_check_idx_panic(ArrayMeta const*const self, int const idx);

#define apppend_generic(array, meta, elem) \
array[array_meta_next_index(meta)] = (elem)

#define append(obj, elem) apppend_generic((obj)->array, &(obj)->meta, elem)

#endif
