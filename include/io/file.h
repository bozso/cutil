#ifndef CUTIL_IO_FILE
#define CUTIL_IO_FILE

#include <stdio.h>
#include "writer.h"

#ifndef CUTIL_IO_MAX_FILES
#define CUTIL_IO_MAX_FILES 100
#endif

typedef struct File {
    FILE* file;
    io_write write;
} File;

File io_new_file(FILE* file);

typedef enum io_std {
    IO_STDOUT,
    IO_STDERR,
    IO_STD_MAX
} io_std;

IWriter* io_get(io_std mode);

#endif
