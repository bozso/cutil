#include "array/array.hpp"

namespace cpputil {
namespace array {

Meta Config::allocate_impl(size cap, std::size_t elem_size) {
  this->allocator.allocate(elem_size * cap);
}
} // namespace array
} // namespace cpputil
