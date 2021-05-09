#ifndef CPPUTIL_STRING_STRING_HPP
#define CPPUTIL_STRING_STRING_HPP

#include "array/array.hpp"
#include "error/error.hpp"
#include "result/result.h"

#include <cstdint>

namespace cpputil {
namespace string {

class Service {
  public:
    virtual Result intern(char const* const str);
    virtual Result concatenate(result_id, result_id);
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
