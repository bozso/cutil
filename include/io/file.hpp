#ifndef HH_UTIL_IO_FILE
#define HH_UTIL_IO_FILE

#include <cstdio>
#include <memory>
#include "util/common/types.hh"

namespace util {
namespace io {

enum class Open {
    Read, Write, ReadWrite, Append
};

enum class Input {
    Binary, Text
};

struct File {
    struct Deleter {
      void operator()(std::FILE* file) { std::fclose(file); }
    };
    
    enum class Mode : int {
        Read      = 1,
        Write     = 2,
        Append    = 4,
        ReadWrite = 8,
        Binary    = 16,
        Text      = 32,
    };
    
    using ptr = std::unique_ptr<std::FILE, Deleter>;
    
    static File open(common::const_str path, Open const open,
                     Input const input);    

    File() = default;
private:
    ptr m_file;
    
    explicit File(std::FILE*const file);
};

struct Binary {
    static Binary read(common::const_str path);
    static Binary write(common::const_str path);
    static Binary append(common::const_str path);
    
    Binary() = default;
private:
    static Binary open(common::const_str path, Open const open);

    File m_file;
};

}
}

#endif
