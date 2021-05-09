#include "array/array.hpp"

namespace cpputil {
namespace array {

Meta Config::allocate_impl(size cap, std::size_t elem_size) {
    return Meta{.cfg = this};
}
} // namespace array
} // namespace cpputil
