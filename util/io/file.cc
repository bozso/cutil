#include <unordered_map>
#include "file.hh"

namespace {
using Mode = util::io::File::Mode;

inline Mode operator|(Mode const one, Mode const two)
{
    return static_cast<Mode>(
        static_cast<int>(one) | static_cast<int>(two)
    );
}
    
static auto const mode_map = std::unordered_map<Mode const, char const*const>{
    {Mode::Read,  "r"},
    {Mode::Read | Mode::Text,  "r"},
    {Mode::Read | Mode::Binary,  "rb"},
    {Mode::Write, "w"},
    {Mode::Write | Mode::Text, "w"},
    {Mode::Write | Mode::Binary, "wb"},
    {Mode::Append, "a"},
    {Mode::Append | Mode::Text, "a"},
    {Mode::Append | Mode::Binary, "ab"},
    {Mode::ReadWrite, "rw"},
    {Mode::ReadWrite | Mode::Text, "rw"},
    {Mode::ReadWrite | Mode::Binary, "rwb"},
};
}

namespace util {
namespace io {

File::File(std::FILE*const file)
{
    if (file == NULL) {
        // error
    }
    
    m_file = File::ptr(file);
}

File File::open(common::const_str path, File::Mode const mode)
{
    return File(std::fopen(path, mode_map.at(mode)));
}

}
}
