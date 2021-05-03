#include "cutil/common/panic.h"
#include "cutil/common/macros.h"
#include "cutil/common/array_meta.h"
#include "cutil/common/ids.h"
#include "files.h"

int io_files_close(IOFiles*const self)
{
    int status = 0;
    for (int ii = 0; ii < self->meta.current; ii++) {
        status = status || fclose(self->array[ii]);
        
    }
    return status;
}

int io_files_write(IOFiles*const self, int const idx, const_str msg)
{
    array_meta_check_idx_panic(&self->meta, idx);
    return fputs(msg, self->array[idx]);
}

int io_files_flush(IOFiles*const self, int const idx)
{
    array_meta_check_idx_panic(&self->meta, idx);
    return fflush(self->array[idx]);
}

int io_files_flush_all(void*const self_)
{
    CUTIL_SELF(IOFiles*const, self_);

    int status = 0;
    for (int ii = 0; ii < self->meta.current; ii++) {
        status = status || io_files_flush(self, ii);
    }

    return status;
}

int io_files_write_all(void*const self_, const_str msg)
{
    CUTIL_DEFAULT_SELF(IOFiles);
    
    int status = 0;
    for (int ii = 0; ii < self->meta.current; ii++) {
        status = status || fputs(msg, self->array[ii]);
    }
    
    return status;
}

int array_meta_to_string(void*const self_, IWriter*const w)
{
    CUTIL_DEFAULT_SELF(ArrayMeta);

    return io_fprintf(w, "ArrayMeta{current: %d, capacity: %d}",
        self->current, self->capacity);
}

static int array_meta_to_string_fmt(void*const self_, const_str fmt, IWriter*const w)
{
    int status = io_fprintf(w, fmt);
    return status + array_meta_to_string(self_, w);
}

int cm_ids_to_string(void*const self_, IWriter*const w)
{
    CUTIL_DEFAULT_SELF(IDs);    
    
    int status = array_meta_to_string_fmt((void*)&self->meta, "IDs{\n\tmeta: ", w);
    status += io_fprintf(w, ",\n\tarray: {");
    
    int const curr = self->meta.current;
    
    for (int ii = 0; ii < curr - 1; ii++) {
        status += io_fprintf(w, "%d, ", self->array[ii]);
    }
    
    return status + io_fprintf(w, "%d}\n}", self->array[curr - 1]);
}

static int io_files_to_string(void*const self_, IWriter *w)
{
    CUTIL_DEFAULT_SELF(IOFiles);
    
    int status = array_meta_to_string_fmt((void*)&self->meta, "Files{\n\tmeta: ", w);
    status += io_fprintf(w, ",\n\tarray: {");
    
    int const curr = self->meta.current;
    
    for (int ii = 0; ii < curr - 1; ii++) {
        status += io_fprintf(w, "%p, ", self->array[ii]);
    }
    
    return status + io_fprintf(w, "%p}\n}", self->array[curr - 1]);
}

static IOFilesMethods const files_methods = {
    .write = io_files_write_all,
    .flush = io_files_flush_all,
    .to_string = io_files_to_string,
};

IOFiles io_new_files(int const capacity)
{
    return (IOFiles) {
        .meta = new_array_meta_with_capacity(capacity),
        .methods = &files_methods,
    };
}

ID io_files_new(IOFiles*const self, FILE*const file)
{
    ID const next = array_meta_next_index(&self->meta);
    self->array[next] = file;
    return next;
}

ID io_files_must_open(IOFiles*const self, const_str path, const_str mode)
{
    FILE*const f = fopen(path, mode);

    if (f == NULL) {
        panicf("Could not open file '%s'!\n", path);
    }
    
    return io_files_new(self, f);
}
