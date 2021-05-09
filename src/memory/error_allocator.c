#include "error/error.h"
#include "memory/allocator.h"

struct Allocator_t {
  struct Allocator *allocator;
  Error *status;
};

static void *allocate_(struct Allocator *const self, size_t const size) {
  if (self->self->status == NULL) {
    return NULL;
  }

  void *const ptr = allocate_impl(self, size);

  if (ptr == NULL) {
    self->self->status = ErrorFail;
  }

  return ptr;
}

static void *reallocate_error_handling(struct AllocateErrorHandling *const self,
                                       void *ptr, size_t const size) {
  if (is_error(self->status)) {
    return NULL;
  }

  ptr = self->allocator->reallocate(self->allocator, ptr, size);

  if (ptr == NULL) {
    self->status = ErrorFail;
  }

  return ptr;
}

static void deallocate_error_handling(struct AllocateErrorHandling *const self,
                                      void *const ptr) {
  self->allocator->deallocate(self->allocator, ptr);
}

static struct AllocatorMethods const methods = {};

struct Allocator
init_allocator_with_errors(struct AllocateErrorHandling *const self,
                           struct Allocator *const allocator) {
  self->allocator = allocator;
  return *(allocator);
  {
      .allocator = self,
      .allocate = allocate,
      .reallocate = reallocate,
      .deallocate = deallocate,
  };
}
