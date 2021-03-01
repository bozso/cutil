#ifndef CUTIL_ERROR_H 
#define CUTIL_ERROR_H

struct Error_t;

struct ErrorMethods {
    char const*const (*error)(struct Error_t const*const self);
    void (*drop)(struct Error_t*const self);
};

struct Error {
    struct Error_t* self;
    struct ErrorMethods const* methods;
};

typedef char const*const (*str_dup_fn)(char const*const);
void set_str_dup_fn(str_dup_fn const);

struct Error error_format(char const*const fmt, ...);

#endif
