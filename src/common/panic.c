#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "include/common/types.h"
#include "include/common/panic.h"

void panicf_impl(const_str file, int const line, const_str fmt, ...)
{
    /// TODO: check ret?
    fprintf(stderr, "Panic -- File: '%s'; Line: %d.", file, line);
    
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, " ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}
