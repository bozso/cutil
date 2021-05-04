#ifndef CPPUTIL_ERROR_ERROR_HPP
#define CPPUTIL_ERROR_ERROR_HPP

#include "string/string.hpp"

namespace cpputil {
    namespace error {
        class Error {
            public:
                virtual String error() const = 0;
                virtual ~Error() = default;
        };
    }
}

#endif
