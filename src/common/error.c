#include "include/common/types.h"
#include "include/common/error.h"

int is_error(Status const status)
{
    return status <= StatusPrintError;
}
