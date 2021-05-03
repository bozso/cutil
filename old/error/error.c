#include "status.h"

int is_error(ErrorStatus const status)
{
    return status <= CUTIL_ERROR_STATUS_FAIL;
}
