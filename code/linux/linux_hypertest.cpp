#include "../hypertest_test.h"
#include "../hypertest_types.h"
#include "../hypertest_asserts.h"

int 
RunTesting(int argc, char **argv)
{
    uint64_t Failed = 0;
    size_t *FailedTestCases = 0;
    size_t NumberOfFailedTestCases = 0;
    uint64_t RanTests = 0;

    // TODO: Check command line args for --help etc..

    for (uint32_t Index = 0; Index < TestState.NumberOfTests; ++Index)
    {
        RanTests++;
    }

    printf("    __  __                     ______          __ \n");
    printf("   / / / /_  ______  ___  ____/_  __/__  _____/ /_\n");
    printf("  / /_/ / / / / __ \\/ _ \\/ ___// / / _ \\/ ___/ __/\n");
    printf(" / __  / /_/ / /_/ /  __/ /   / / /  __(__  ) /_  \n");
    printf("/_/ /_/\\__, / .___/\\___/_/   /_/  \\___/____/\\__/  \n");
    printf("      /____/_/                                    \n");
    printf("Created by Oskar Mendel.\n\n");

    printf("[==========]");
    printf(" Running %I64u tests.\n", (uint64_t) RanTests);
    
    // NOTE: Run tests.
    for (uint64_t Index = 0; Index < TestState.NumberOfTests; Index++)
    {
        int Result = 0;
        int64_t NanoSeconds = 0;

        printf("[ RUN      ]");
        printf(" %s\n", TestState.Tests[Index].Name);
        
        // TODO: If we want file output then do something here..

        TestState.Tests[Index].Function(&Result, TestState.Tests[Index].Index);

        if (Result != 0)
        {
            size_t FailedTestCaseIndex = NumberOfFailedTestCases++;
            FailedTestCases = (size_t *) realloc((void *)FailedTestCases, sizeof(size_t)*NumberOfFailedTestCases);
            FailedTestCases[FailedTestCaseIndex] = (size_t)Index;
            Failed++;

            printf("[  FAILED  ]");
            printf(" %s (%I64u ns)\n", TestState.Tests[Index].Name, NanoSeconds);
        }
        else
        {
            printf("[       OK ]");
            printf(" %s (%I64u ns)\n", TestState.Tests[Index].Name, NanoSeconds);
        }
    }

    // NOTE: Printing overview data of entire ran test.
    printf("[==========]");
    printf(" %I64u test cases ran.\n", RanTests);

    printf("[  PASSED  ]");
    printf(" %I64u tests.\n", RanTests - Failed);

    if (Failed)
    {
        printf("[  FAILED  ]");
        printf(" %I64u tests, listed bellow:\n", Failed);

        // TODO: For loop and loop through failed tests.
        for (uint64_t Index = 0; Index < NumberOfFailedTestCases; ++Index)
        {
            printf("[  FAILED  ]");
            printf(" %s\n", TestState.Tests[FailedTestCases[Index]].Name);
        }
    }

    // NOTE: Cleanup of allocated test data
    for (uint64_t Index = 0; Index < TestState.NumberOfTests; ++Index)
    {
        free((void *) TestState.Tests[Index].Name);
    }

    free((void *) TestState.Tests);

    return ((int32_t) Failed);
}