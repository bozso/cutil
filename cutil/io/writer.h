#ifndef WRITER_H 
#define WRITER_H

struct Writer_t;

struct WriterMethods {
    int (*write)(struct Writer_t*const, char const*const bytes);
    int (*drop)(struct Writer_t*const);
};

struct Writer {
    struct Writer_t* self;
    struct WriterMethods const* methods;
};

#endif
