#include "file.h"

static int io_file_write(void*const self_, const_str msg)
{
    return fputs(msg, ((File*const) self_)->file);
}

File io_new_file(FILE* file)
{
    return (File) {
        .file = file,
        .write = io_file_write,
    };
}

typedef struct FileCache {
    File files[IO_STD_MAX];
    IWriter writers[IO_STD_MAX];
    int is_set[IO_STD_MAX];
} FileCache;

static FileCache file_cache = {0};

static FILE* get(io_std mode)
{
    FILE* file = NULL;
    
    switch (mode) {
    case IO_STDOUT:
        file = stdout;
        break;
    case IO_STDERR:
        file = stderr;
        break;
    default:
        break;
    }
    
    return file;
}

IWriter* io_get(io_std mode)
{
    if (!file_cache.is_set[mode]) {
        file_cache.files[mode] = io_new_file(get(mode));
        
        file_cache.writers[mode] =
        io_new_writer(&file_cache.files[mode], &io_file_write);
        file_cache.is_set[mode] = 1;
    }
    
    return &file_cache.writers[mode];
}
