/**
 * @depends: stdio.h
 */

#define XSTR(a) STR(a)
#define STR(a) #a

#define LOG printf("File: %s -- line: %d\n", __FILE__, __LINE__)
