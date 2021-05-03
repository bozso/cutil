#ifndef WRITER_H 
#define WRITER_H

struct Writer_t;

struct WriterMethods {
    int (*write)(struct Writer_t*const, char const*const bytes);
    int (*drop)(struct Writer_t*const);
};

struct Writer {
    struct Writer_t* wr;
    struct WriterMethods const* methods;
};

struct Writer open_file(char const*const path);
struct Writer create_file(char const*const path);
struct Writer append_file(char const*const path);
struct Writer new_string_buffer(void);
char const*const get_buffer(struct Writer const*const self);

#endif
