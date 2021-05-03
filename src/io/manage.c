#include "cutil/io/manage.h"

ErrorStatus use_file(FileCreator creator, fn_use_file fn, void*const data)
{
    FILE* file = NULL;
    ErrorStatus status = creator.file_creator(creator.self, &file);

    if (is_error(status)) {
        return status;
    }

    status = fn(data, file);

    if (is_error(status)) {
        return status;
    }
}
