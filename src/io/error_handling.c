typedef struct ErrorHandler {
    void (*handle)(void*const self);
} ErrorHandler;

typedef struct IErrorHandler {
    void* self;
    ErrorHandler* handler;
} IErrorHandler;

static void ignore_impl(void*const self)
{
    return;
}

static ErrorHandler ignore = {
    .handle = ignore_impl,
};


IErrorHandler const strategies[] = {
    {0, &ignore},
};

/*
static void exit_handle(Self *self, int const is_err)
{
    if (is_err) {
        panicf("Error while writing to stream! Exiting.\n");
    }
    return;
}

struct Handler Exit(void)
{
    return (struct Handler) {
        .self = NULL,
        .handle = exit_handle,
    };
    
}
*/
