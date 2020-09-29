/**
 * @file
 * @author István Bozsó <bozso.istvan@csfk.mta.hu>
 * @version 0.1
 * 
 * @depends: stdio.h, stdarg.h, self/types.h, 
 */

/**
 * Prints the formatted message defined by parameters and terminates
 * program execution.
 * 
 * Usage recommended with the panicf macro.
 * @see panicf
 * 
 * @param file Name of the file where this function was called.
 * @param line Line number of the  file where this function was called.
 * @param fmt Format string.
 */
void panicf_impl(const_str file, int const line, const_str fmt, ...);

/**
 * Macro for easier usage of the panicf_impl function.
 * @see panicf_impl
 */
#define panicf(...) panicf_impl(__FILE__, __LINE__, __VA_ARGS__)
