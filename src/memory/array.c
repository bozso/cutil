#include "memory/array.h"
#include "memory/allocator.h"
#include "result/error.h"
#include "result/option.h"
#include "result/result.h"

struct ArrayConfig new_array_config(struct Allocator* const alloc,
                                    array_size default_cap) {
    return (struct ArrayConfig){
        .allocator = alloc,
        .default_cap = default_cap,
    };
}

Error array_init_impl(struct Array* const arr, struct ArrayConfig* const conf,
                      size_t const type_size, size_t const cap) {

    ResultPtr ptr = allocate_err(conf->allocator, type_size * cap);
    result_ptr_err(ptr);

    arr->type_size = type_size;
    arr->config = conf;
    arr->len = arr->cap = cap;
    arr->buffer = ptr.ptr_or_err.ptr;

    return error_ok();
}

#if 0
ArrayMeta new_array_meta(Allocator* allocator, byte element_size) {
    return (ArrayMeta){
        .allocator = allocator,
        .element_size = element_size,
    };
}

ErrorStatus array_with_capacity(Array* const self, ArrayMeta const* const meta,
                                uint64_t capacity) {
    self->meta = meta;
    self->capacity = self->length = capacity;
    self->data = NULL;
    return array_resize(self, capacity);
}

ErrorStatus array_resize(Array* const self, uint64_t nelem) {
    ErrorStatus err = ErrorOk;

    self->data = reallocate(self->meta->allocator, self->data,
                            self->meta->element_size * nelem);

    if (self->data == NULL) {
        err = ErrorFail;
    }

    return err;
}

static ErrorStatus drop(Array* const self) {
    deallocate(self->meta->allocator, self->data);
    return ErrorOk;
}

static const ArrayMetaMethods methods = {
    .drop = (cutil_memory_drop)drop,
};

ArrayMetaMethods const* const array_meta_methods(void) { return &methods; }
#endif
