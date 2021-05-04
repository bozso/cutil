#ifndef CPPUTIL_ARRAY_ARRAY_HPP
#define CPPUTIL_ARRAY_ARRAY_HPP

#include <c++/7/bits/c++config.h>
#include <cstdint>

namespace cpputil {
    namespace array {
        using size = uint64_t;

        class Meta {
            size len, capacity;
            std::size_t elem_size;
        };

        class Config {
            public:
                template<class T>
                Meta allocate(size cap);

                Meta allocate_impl(size cap, std::size_t elem_size);

                size default_capacity;
        };
    }
}

#endif
