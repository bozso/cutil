#ifndef CUTIL_IO_MANAGE 
#define CUTIL_IO_MANAGE

#include <stdio.h>

#include "cutil/error/status.h"

typedef ErrorStatus *create_file(void*const self, FILE**const file);
typedef ErrorStatus *fn_use_file(void*const data, FILE*const file);

typedef struct FileCreator {
    void*const self;
    create_file const file_creator;
} FileCreator;

ErrorStatus use_file(FileCreator creator, fn_use_file fn, void*const data);

#endif
