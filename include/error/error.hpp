#ifndef CPPUTIL_ERROR_ERROR_HPP
#define CPPUTIL_ERROR_ERROR_HPP

#include "string/string.hpp"

namespace cpputil {
namespace error {
class Service {
  public:
    virtual result_id error(result_id) const = 0;
    virtual ~Service() = default;
};
} // namespace error
} // namespace cpputil

#endif
