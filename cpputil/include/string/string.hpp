#ifndef CPPUTIL_STRING_STRING_HPP
#define CPPUTIL_STRING_STRING_HPP

namespace cpputil {
    class String {
        public:
            virtual ~String() = default;
    };

    class CharacterBuffer : public String {
        CharacterBuffer(array::Config const&, array::size capacity);
        public:
            ~CharacterBuffer() = default;
    };
}

#endif
