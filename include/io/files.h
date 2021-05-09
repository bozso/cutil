#ifndef H_CUTIL_IO_FILES
#define H_CUTIL_IO_FILES

#include "io.h"
#include "cutil/common/array_meta.h"

typedef struct IOFilesMethods {
    io_write write;
    io_flush flush;
    io_string to_string;
} IOFilesMethods;

typedef struct IOFiles {
    ArrayMeta meta;
    FILE** array;
    IOFilesMethods const*const methods;
} IOFiles;

#endif
