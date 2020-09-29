#include "types.h"
#include "error.h"

int is_error(Status const status)
{
    return status <= StatusPrintError;
}
