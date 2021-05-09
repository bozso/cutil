#ifndef CPPUTIL_ARRAY_ARRAY_HPP
#define CPPUTIL_ARRAY_ARRAY_HPP

#include <c++/7/bits/c++config.h>
#include <cstdint>

#include "memory/allocator.hpp"

namespace cpputil {
namespace array {
using size = uint64_t;

class Config;

class Meta {
    Config& cfg;
    size len, capacity;
    std::size_t elem_size;
};

class Config {
    using Allocator = memory::Allocator;

  public:
    Config(Allocator&, size default_capacity);
    template <class T> Meta allocate(size cap);

    Meta allocate_impl(size cap, std::size_t elem_size);

    size default_capacity;

  private:
    Allocator& allocator;
};
} // namespace array
} // namespace cpputil

#endif
