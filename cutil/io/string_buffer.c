#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "writer.h"

struct Writer_t {
    char* buffer;
};

static int write(struct Writer_t*const wr, char const*const bytes) {
    if (wr->buffer == NULL) {
        wr->buffer = malloc(strlen(bytes) + 1);
        strcpy(wr->buffer, bytes);
        return 0;
    }

    int const needed = strlen(wr->buffer) + strlen(bytes) + 1;
    char*const new_buf = malloc(sizeof(char) * needed);
    strcpy(new_buf, wr->buffer);
    free(wr->buffer);
    strcat(new_buf, bytes);
    wr->buffer = new_buf;
    return 0;
}

static int drop(struct Writer_t*const wr) {
    free(wr->buffer);
    free(wr);
    return 0;
}

static struct WriterMethods const methods = {
    .write = write,
    .drop = drop,
};

<<<<<<< HEAD
struct Writer*const new_string_buffer(void) {
    struct Writer* const wr = malloc(sizeof(struct Writer));
    wr->self = malloc(sizeof(struct Writer_t));
    wr->self->buffer = NULL;
    wr->methods = &methods;

    return wr;
}

char const*const get_buffer(struct Writer const*const self) {
    return self->self->buffer;
=======
struct Writer new_string_buffer(void) {
    struct Writer self;
    self.wr = malloc(sizeof(struct Writer_t));
    self.wr->buffer = NULL;
    self.methods = &methods;

    return self;
}

char const*const get_buffer(struct Writer const*const self) {
    return self->wr->buffer;
>>>>>>> f0ff2e7
}
