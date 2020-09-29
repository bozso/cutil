/**
 * @depends: panic.h, types.h
 */

typedef struct Arguments {
    int const nargs;
    const_str*const args;
} Arguments;

Arguments new_args(int const argc, const_str*const argv);
Arguments args_shift(Arguments const self, int const nargs);
const_str args_get(Arguments const self, int const idx);

Arguments empty_arguments(void);
