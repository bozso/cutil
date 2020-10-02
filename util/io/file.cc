#include <utility>
#include <unordered_map>

#include "file.hh"
#include "util/common/ptr.hh"

namespace {
using Open = util::io::Open;
using Input = util::io::Input;

// from: https://www.techiedelight.com/use-std-pair-key-std-unordered_map-cpp/
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

using pair = std::pair<Open, Input>;    
using map = std::unordered_map<pair const, util::common::const_str, pair_hash>;

static auto const mode_map = map{
    {{Open::Read, Input::Text},    "r"},
    {{Open::Read, Input::Binary},  "rb"},
    {{Open::Write, Input::Text},   "w"},
    {{Open::Write, Input::Binary}, "wb"},
    {{Open::Append, Input::Text},    "a"},
    {{Open::Append, Input::Binary},  "ab"},
};

}

namespace util {
namespace io {

File::File(std::FILE*const file)
{
    if (file == nullptr) {
        throw util::common::NullPointer();
    }
    
    m_file = File::ptr(file);
}

File File::open(common::const_str path, Open const open, Input const input)
{
    return File(std::fopen(path, mode_map.at({open, input})));
}

Binary Binary::open(common::const_str path, Open const open)
{
    Binary b;
    b.m_file = File::open(path, open, Input::Binary);
    return b;
}

}
}
