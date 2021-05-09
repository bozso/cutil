#ifndef CPPUTIL_MEMORY_ALLOCATOR_HPP
#define CPPUTIL_MEMORY_ALLOCATOR_HPP

#include <cstdint>

namespace cpputil {
namespace memory {
class Allocator {
  public:
    template <class T> T* const allocate(std::size_t elems) {
        return static_cast<T*>(this->allocate_impl(sizeof(T) * elems));
    }

    virtual void* allocate_impl(std::size_t) = 0;
    virtual ~Allocator() = default;
};
} // namespace memory
} // namespace cpputil

#endif
