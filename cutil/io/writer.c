#include <stdio.h>
#include <stdlib.h>

#include "cutil/common/macros.h"
#include "writer.h"

IWriter io_new_writer(void*const self, io_write writer)
{
    return (IWriter) {
        .self = self,
        .write = writer,
    };
}

Status io_vfprintf(IWriter const*const writer, char *buffer,
                   const_str fmt, va_list args)
{
    if (vsprintf(buffer, fmt, args) < 0) {
        return StatusPrintError;
    }
    
    if (writer->write(writer->self, buffer) < 0) {
        return StatusFail;
    }
    
    return StatusOk;
}

Status io_fprintf(IWriter const*const writer, const_str fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    int const size = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    
    if (size < 0) {
        return StatusPrintError;
    }
    
    char *const buffer = malloc(size + 1);
    
    if (buffer == NULL) {
        return StatusPrintError;
    }

    va_start(args, fmt);
    Status const status = io_vfprintf(writer, buffer, fmt, args);
    va_end(args);
    
    free(buffer);
    return status;
}

static int indent_writer_write(void*const self_, const_str msg)
{
    CUTIL_DEFAULT_SELF(IndentWriter);
    return io_fprintf(self->writer, "%*s", self->n_indent, msg);
}

static IndentWriterMethods indent_writer_methods = {
    .write = indent_writer_write,
};

IndentWriter io_new_indent_writer(IWriter* wr, int const n_indent)
{
    return (IndentWriter) {
        .writer = wr,
        .n_indent = n_indent,
        .methods = &indent_writer_methods,
    };
}
