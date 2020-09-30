#ifndef H_CUTIL_IO_WRITER
#define H_CUTIL_IO_WRITER

#include <stdarg.h>

#include "cutil/common/types.h"
#include "cutil/common/error.h"

typedef int (*io_write)(void*const self, const_str msg);

typedef struct IWriter {
    void* self;
    io_write write;
} IWriter;

IWriter io_new_writer(void*const self, io_write writer);
Status io_vfprintf(IWriter const*const writer, char *buffer,
                   const_str fmt, va_list args);
Status io_fprintf(IWriter const*const writer, const_str fmt, ...);


typedef struct IndentWriterMethods {
    io_write write;
} IndentWriterMethods;

typedef struct IndentWriter {
    IWriter* writer;
    int const n_indent;
    IndentWriterMethods* methods;
} IndentWriter;

IndentWriter io_new_indent_writer(IWriter* wr, int const n_indent);

#endif
