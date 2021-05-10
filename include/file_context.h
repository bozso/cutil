#ifndef CUTIL_FILE_CONTEXT_H
#define CUTIL_FILE_CONTEXT_H

struct FileContext {
    char const* const name;
    int const line;
};

#define FILE_CONTEXT                                                          \
    (struct FileContext) { .name = __FILE__, .line = __LINE__, }

#endif
