#ifndef HH_UTIL_COMMON_PTR
#define HH_UTIL_COMMON_PTR

#include <exception>

namespace util {
namespace common {

template<class T>
struct Pointer {
    explicit Pointer(T*const ptr) noexcept : m_ptr(ptr) {}
    
    T*const get(void) noexcept
    {
        return m_ptr;
    }
private:
    T*const m_ptr;
};


struct NullPointer : std::exception {};

template<class T>
struct NotNull : Pointer<T> {
    explicit NotNull(T*const ptr) {
        if (ptr == nullptr) {
            throw NullPointer();
        }
    }
};
    
}
}

#endif
