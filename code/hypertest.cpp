#include "hypertest.h"

// NOTE: Global Unittest state that will be executed.
struct test_state TestState;

#if BUILD_WINDOWS
#include "win32/win32_hypertest.cpp"
#elif BUILD_LINUX
#include "linux/linux_hypertest.cpp"
#endif

int 
main(int argc, char **argv)
{ 
    return RunTesting(argc, argv);
}