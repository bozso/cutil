#ifndef CUTIL_IO_FORMATTER_H
#define CUTIL_IO_FORMATTER_H

#include "result/result.h"

struct Formatter_t;

struct FormatterMethods {
    Option (*write)(struct Formatter_t* const self, char const* const data);
};

struct Formatter {
    struct Formatter_t* self;
    struct FormatterMethods const* const methods;
};

#endif
