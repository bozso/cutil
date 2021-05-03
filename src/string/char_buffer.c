#include "string.h"
#include "array/array.h"

struct String_t {
    struct ArrayMeta meta;
    char* buffer;
};

static struct StringMethods const methods = {

};

String new_char_buffer(struct ArrayConfig const*const config, Error* err)
{
    struct String_t result;
    array_allocate(config, &result.meta, &result.buffer, err);

    return (String) {
        .self = result,
        .methods = &methods,
    }
}
