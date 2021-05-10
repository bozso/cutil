#ifndef CUTIL_STRING_H
#define CUTIL_STRING_H

#include "error/error.h"

struct StringMethods {
    struct Error (*destroy)(struct String_t*const self);
};

#endif
