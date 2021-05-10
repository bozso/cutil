#include "result/result.hpp"

namespace cpputil {
UnhandledError::UnhandledError(Result::id id_) noexcept { this->id_ = id_; }

bool Result::is_error(void) noexcept { return this->status == Status::Error; }

Result::id Result::unwrap(void) {
    if (this->is_error()) {
        throw UnhandledError(this->id_);
    }
    return this->id_;
}

} // namespace cpputil
