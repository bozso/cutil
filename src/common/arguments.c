#include "arguments.h"
#include "panic.h"

Arguments new_args(int const argc, const_str* const argv) {
    return (Arguments){
        .nargs = argc,
        .args = argv,
    };
}

Arguments args_shift(Arguments const self, int const nargs) {
    return new_args(self.nargs - nargs, self.args + nargs);
}

const_str args_get(Arguments const self, int const idx) {
    if (idx >= self.nargs) {
        panicf("Index %d is out of bounds of limit %d!\n", idx, self.nargs);
    }

    return self.args[idx];
}

static Arguments const EmptyArguments = {
    .nargs = 0,
    .args = 0,
};

Arguments empty_arguments(void) { return EmptyArguments; }
