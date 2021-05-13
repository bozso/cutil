#ifndef H_CUTIL_COMMON_PANIC
#define H_CUTIL_COMMON_PANIC

#include "file_context.h"
#include <stdarg.h>

/**
 * @file
 * @author István Bozsó <bozso.istvan@csfk.mta.hu>
 * @version 0.1
 *
 */

typedef void (*panic_fn)(struct FileContext const, char const* const, va_list);

/**
 * Prints the formatted message defined by parameters and terminates
 * program execution.
 *
 * Usage recommended with the panicf macro.
 * @see panicf
 *
 * @param file_context FileContext struct containing filename and file line.
 * @param fmt Format string.
 */
void panicf_impl(struct FileContext const file, char const* const fmt, ...);

/**
 * Macro for easier usage of the panicf_impl function.
 * @see panicf_impl
 */
#define panicf(...) panicf_impl(FILE_CONTEXT, __VA_ARGS__)

#endif
