#include "memory/allocator.h"
#include "error/error.h"

void *allocate_impl(struct Allocator *const self, size_t const size) {
  return self->methods->allocate(self, size);
}

void *reallocate_impl(struct Allocator *const self, void *ptr,
                      size_t const size) {
  return self->methods->reallocate(self, ptr, size);
}

void deallocate(struct Allocator *const self, void *const ptr) {
  return self->deallocate(self, ptr);
}
