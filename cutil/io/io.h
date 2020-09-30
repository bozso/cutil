#ifndef H_CUTIL_IO
#define H_CUTIL_IO

#include "writer.h"

typedef int (*io_flush)(void*const);
typedef int (*io_string)(void*const, IWriter*);

#include "file.h"
#include "error_handling.h"

#endif
