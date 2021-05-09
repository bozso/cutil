#ifndef CPPUTIL_STRING_STRING_HPP
#define CPPUTIL_STRING_STRING_HPP

#include "array/array.hpp"
#include "error/error.hpp"

#include <cstdint>

namespace cpputil {
namespace string {

using id = std::size_t;

class Service {
  public:
    virtual Result<id> intern(char const* const str);
    virtual ~Service() = default;
};

class CharacterBuffer {
    CharacterBuffer(array::Config const&, array::size capacity);

  public:
    ~CharacterBuffer() = default;
};
} // namespace string
} // namespace cpputil

#endif
