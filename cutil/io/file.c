#include <stdio.h>
#include <stdlib.h>
#include "writer.h"

struct Writer_t {
    FILE* file;
};
<<<<<<< HEAD

static int write(struct Writer_t*const wr, char const*const bytes) {
    return fputs(bytes, wr->file);
}

static int drop(struct Writer_t*const wr) {
    fclose(wr->file);
    free(wr);
    return 0;
}

static struct WriterMethods const methods = {
    .write = write,
    .drop = drop,
};

struct Writer* open_file(char const*const path, char const*const mode)
{
    struct Writer* wr = malloc(sizeof(struct Writer));
    wr->self = malloc(sizeof(struct Writer_t));
    wr->self->file = fopen(path, mode);
    wr->methods = &methods;
    return wr;
=======

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

static struct Writer _open_file(char const*const path, char const*const mode) {
    struct Writer self;
    self.wr = malloc(sizeof(struct Writer_t));
    self.wr->file = fopen(path, mode);
    self.methods = &methods;
    return self;
}

struct Writer create_file(char const*const path) {
    return _open_file(path, "w");
>>>>>>> f0ff2e7
}

struct Writer open_file(char const*const path) {
    return _open_file(path, "r");
}

