#ifndef HYPERTEST_H
#define HYPERTEST_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// NOTE(Oskar): Pre-main execution of functions.
#ifdef __cplusplus
#define UNITTEST_INITIALIZER(f) \
    static void f(void); \
    struct f##_t_ { f##_t_(void) { f(); } }; static f##_t_ f##_; \
    static void f(void)
#elif defined(_MSC_VER)
#pragma section(".CRT$XCU",read)
#define UNITTEST_INITIALIZER2_(f,p) \
    static void f(void); \
    __declspec(allocate(".CRT$XCU")) void (*f##_)(void) = f; \
    __pragma(comment(linker,"/include:" p #f "_")) \
    static void f(void)
#ifdef _WIN64
#define UNITTEST_INITIALIZER(f) UNITTEST_INITIALIZER2_(f,"")
#else
#define UNITTEST_INITIALIZER(f) UNITTEST_INITIALIZER2_(f,"_")
#endif
#else
#define UNITTEST_INITIALIZER(f) \
    static void f(void) __attribute__((constructor)); \
    static void f(void)
#endif

typedef void (*Unittest_Testcase)(int *, size_t);

struct test
{
    Unittest_Testcase Function;
    size_t Index;
    char *Name;
};

struct test_state
{
    struct test *Tests;
    size_t NumberOfTests;
    FILE *Output;
};

#endif // HYPERTEST_H