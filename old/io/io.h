#ifndef H_CUTIL_IO
#define H_CUTIL_IO

#include "writer.h"

typedef int (*io_flush)(void*const);
typedef int (*io_close)(void*const);
typedef int (*io_string)(void*const, IWriter*const);

typedef struct IOWriteFlush {
    io_write write;
    io_flush flush;
} IOWriteFlush;

#include "file.h"
#include "error_handling.h"

#endif
