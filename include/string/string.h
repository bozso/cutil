#ifndef CUTIL_STRING_H
#define CUTIL_STRING_H

#include "error/error.h"

struct String_t;

struct StringMethods {
    struct Error (*destroy)(struct String_t*const self);
};

typedef struct String {
    struct String_t *self;
    struct StringMethods *methods;
} String;

#endif
