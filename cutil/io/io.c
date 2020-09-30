#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "io.h"

/**
 * @file
 * @author István Bozsó <bozso.istvan@csfk.mta.hu>
 * @version 0.1
 * 
 */

/*
typedef struct FilesMethods {
    io_write write;
    io_flush flush;
    io_string to_string;
} FilesMethods;

typedef struct Files {
    ArrayMeta meta;
    FILE* array[MAX_FILES];
    FilesMethods methods;
} Files;

int io_files_close(Files*const self)
{
    int status = 0;
    for (int ii = 0; ii < self->meta.current; ii++) {
        status = status || fclose(self->array[ii]);
        
    }
    return status;
}

int io_files_write(Files*const self, int const idx, const_str msg)
{
    array_meta_check_idx_panic(&self->meta, idx);
    return fputs(msg, self->array[idx]);
}

int io_files_flush(Files*const self, int const idx)
{
    array_meta_check_idx_panic(&self->meta, idx);
    return fflush(self->array[idx]);
}

int io_files_flush_all(Self self_)
{
    Files*const self = (Files*) self_;

    int status = 0;
    for (int ii = 0; ii < self->meta.current; ii++) {
        status = status || io_files_flush(self, ii);
    }

    return status;
}

int io_files_write_all(Self self_, const_str msg)
{
    Files*const self = (Files*) self_;
    
    int status = 0;
    for (int ii = 0; ii < self->meta.current; ii++) {
        status = status || fputs(msg, self->array[ii]);
    }
    
    return status;
}

int array_meta_to_string(Self self_, IWriter *w)
{
    ArrayMeta const*const self = (ArrayMeta*) self_;
    return io_fprintf(w, "ArrayMeta{current: %d, capacity: %d}",
        self->current, self->capacity);
}

static int array_meta_to_string_fmt(Self self_, const_str fmt, IWriter *w)
{
    int status = io_fprintf(w, fmt);
    return status + array_meta_to_string(self_, w);
}

int cm_ids_to_string(Self self_, IWriter *w)
{
    IDs const*const self = (IDs*) self_;
    
    int status = array_meta_to_string_fmt((Self) &self->meta, "IDs{\n\tmeta: ", w);
    status += io_fprintf(w, ",\n\tarray: {");
    
    int const curr = self->meta.current;
    
    for (int ii = 0; ii < curr - 1; ii++) {
        status += io_fprintf(w, "%d, ", self->array[ii]);
    }
    
    return status + io_fprintf(w, "%d}\n}", self->array[curr - 1]);
}

static int io_files_to_string(Self self_, IWriter *w)
{
    Files const*const self = (Files*) self_;
    
    int status = array_meta_to_string_fmt((Self) &self->meta, "Files{\n\tmeta: ", w);
    status += io_fprintf(w, ",\n\tarray: {");
    
    int const curr = self->meta.current;
    
    for (int ii = 0; ii < curr - 1; ii++) {
        status += io_fprintf(w, "%p, ", self->array[ii]);
    }
    
    return status + io_fprintf(w, "%p}\n}", self->array[curr - 1]);
}

static FilesMethods const files_methods = {
    .write = io_files_write_all,
    .flush = io_files_flush_all,
    .to_string = io_files_to_string,
};

Files io_new_files(void)
{
    return (Files) {
        .meta = new_array_meta_with_capacity(MAX_FILES),
    };
}

ID io_files_new(Files*const self, FILE*const file)
{
    ID const next = array_meta_next_index(&self->meta);
    self->array[next] = file;
    return next;
}

ID io_files_must_open(Files*const self, const_str path, const_str mode)
{
    FILE*const f = fopen(path, mode);

    if (f == NULL) {
        panicf("Could not open file '%s'!\n", path);
    }
    
    return io_files_new(self, f);
}

typedef struct WriteFlush {
    io_write write;
    io_flush flush;
} WriteFlush;
*/


#if 0

typedef struct Stream {
    struct IErrorHandler eh;
    FILE* stream;
} Stream;

typedef struct StreamFactory {
    struct IErrorHandler const eh;
} StreamFactory;

StreamFactory io_new_stream_factory(IErrorHandler const eh)
{
    return (struct StreamFactory) {
        .eh = eh,
    };
}

/**
 * Creates a new Stream struct from a FILE* stream.
 * 
 * @param self the factory struct 
 * @param stream FILE stream to be used 
 * @return a new Stream
 */
Stream io_new_stream(StreamFactory const self, FILE*const stream)
{
    return (struct Stream){
        .stream = stream,
        .eh = self.eh,
    };
}

/**
 * Opens a file from path and sets up the Stream struct.
 * 
 * @param path Path to the file to be opened.
 * @param[out] file to be opened.
 * @return Status of the operation.
 * 
 */
Status io_stream_from_path(StreamFactory const self,
                           const_str path, const_str mode,
                           Stream *stream)
{
    FILE* file = fopen(path, mode);
    
    if (file != NULL) {
        return PError;
    }
    
    *stream = io_new_stream(self, file);
    
    return Ok;
}
#endif
