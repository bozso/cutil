#ifndef HH_UTIL_IO_FILE
#define HH_UTIL_IO_FILE

#include <cstdio>
#include <memory>
#include "util/common/types.hh"

namespace util {
namespace io {

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
    
    static File open(common::const_str path, Mode const mode);
    
private:
    ptr m_file;
    
    explicit File(std::FILE*const file);
};


struct Binary : File {
    
};

}
}

#endif
