#ifndef CUTIL_STRING_DECLARE_H
#define CUTIL_STRING_DECLARE_H

struct String_t;

typedef struct String {
    struct String_t* self;
    struct StringMethods const*const methods;
} String;

#endif
