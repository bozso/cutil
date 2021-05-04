#include "error/status.h"

int is_error(enum ErrorStatus const status)
{
    return status <= CUTIL_ERROR_STATUS_FAIL;
}
