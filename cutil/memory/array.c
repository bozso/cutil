#include "array.h"

ArrayMeta new_array_meta(Allocator* allocator, byte element_size) {
    return (ArrayMeta) {
        .allocator = allocator,
        .element_size = element_size,
    };
}

ErrorStatus array_with_capacity(Array*const self ,ArrayMeta const*const meta, uint64_t capacity) {
    self->meta = meta;
    self->capacity = self->length = capacity;
    self->data = NULL;
    return array_resize(self, capacity);
}

ErrorStatus array_resize(Array*const self, uint64_t nelem) {
    ErrorStatus err = ErrorOk;
    
    self->data = reallocate(self->meta->allocator, self->data,
                            self->meta->element_size * nelem);
    
    if (self->data == NULL) {
        err = ErrorFail;
    }
    
    return err;
}

static ErrorStatus drop(Array*const self) {
    deallocate(self->meta->allocator, self->data);
    return ErrorOk;
}

static const ArrayMetaMethods methods = {
    .drop = (cutil_memory_drop) drop,
};

ArrayMetaMethods const*const array_meta_methods(void)
{
    return &methods;
}
