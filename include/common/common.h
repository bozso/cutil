/**
 * @depends: stdio.h, stdlib.h, stdarg.h
 */

#include "types.h"
#include "macros.h"
#include "error.h"
#include "array_meta.h"
#include "panic.h"

typedef struct Arguments {
    int const nargs;
    const_str*const args;
} Arguments;

Arguments cm_args(int const argc, const_str*const argv)
{
    return (Arguments) {
        .nargs = argc,
        .args = argv,
    };
}

Arguments args_shift(Arguments const self, int const nargs)
{
    return cm_args(self.nargs - nargs, self.args + nargs);
}

const_str args_get(Arguments const self, int const idx)
{
    if (idx >= self.nargs) {
        panicf("Index %d is out of bounds of limit %d!\n", idx,
            self.nargs);
    }
    
    return self.args[idx];
}

static Arguments const EmptyArguments = {
    .nargs = 0,
    .args = NULL,
};
