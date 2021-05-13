#ifndef CUTIL_TEST_TEST_H
#define CUTIL_TEST_TEST_H

typedef void (*test_fn)(void);

void register_test(char const* const name, test_fn);

struct TestCase {
    char* const name;
    test_fn test;
};

void run_test(struct TestCase const);

#endif
