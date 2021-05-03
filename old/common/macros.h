#ifndef H_CUTIL_COMMON_MACROS
#define H_CUTIL_COMMON_MACROS

#include <stdio.h>

#define XSTR(a) STR(a)
#define STR(a) #a

#define LOG printf("File: %s -- line: %d\n", __FILE__, __LINE__)

/**
 * Macros helping to cast a void pointer into the appropriate
 * pointer type, when implementing virtual functions.
 */
#define CUTIL_SELF(type, var)           type self = (type) (var)
#define CUTIL_SELF_PTR(type, var)       CUTIL_SELF(type*, var)
#define CUTIL_SELF_CONST_PTR(type, var) CUTIL_SELF(type const*const, var)
#define CUTIL_MAKE_SELF(type, var)      CUTIL_SELF_CONST_PTR(type, var)
#define CUTIL_DEFAULT_SELF(type)        CUTIL_SELF_CONST_PTR(type, self_)

#endif
