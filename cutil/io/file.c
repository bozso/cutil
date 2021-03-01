#include <stdio.h>
#include <stdlib.h>
#include "writer.h"

struct Writer_t {
    FILE* file;
};

static int write(struct Writer_t*const wr, char const*const bytes) {
    return fputs(bytes, wr->file);
}

static int drop(struct Writer_t*const wr) {
    int status = 0;
    status = fclose(wr->file);
    free(wr);
    return status;
}

static struct WriterMethods const methods = {
    .write = write,
    .drop = drop,
};

struct Writer open_file(char const*const path, char const*const mode)
{
    struct Writer wr;
    wr.self = malloc(sizeof(struct Writer_t));
    wr.self->file = fopen(path, mode);
    wr.methods = &methods;
    return wr;
}
