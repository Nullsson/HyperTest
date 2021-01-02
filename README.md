# HyperTest

![Windows](https://github.com/Nullsson/HyperTest/workflows/Windows/badge.svg?branch=master)
![Linux](https://github.com/Nullsson/HyperTest/workflows/Linux/badge.svg?branch=master)
![MacOs](https://github.com/Nullsson/HyperTest/workflows/MacOs/badge.svg?branch=master)

HyperTest is a small unit testing library built to be simple enough for someone
to skim through the source to understand it as well as having a low learning
curve.

It was created during my work on a project called Mendelcast which is a media sharing / casting application
which includes its own web server. During the development of that project I noticed that manually testing
all the different features of my web server by hand after every change simply took too long so I wanted to automate the
process.

## Usage

HyperTest is based on the idea of [Unity Builds](https://stackoverflow.com/questions/847974/the-benefits-disadvantages-of-unity-builds) (not to be confused with the [Unity Engine](https://unity.com/)). This means the user of HyperTest should preferably follow the conventions used to not worry about complications.

The file:
> hypertest.cpp

defines and declares a main() function to be ran so as a user of HyperTest all you need to do is to include win32_hypertest.cpp
in your test file(s) and when you later compile your tests the execution and bookkeeping of your tests will already be taken care of.

Here is a minimal example unit test written using HyperTest:

```C
#include "../path/to/hypertest.cpp"
#include "FileToTest.cpp"

TEST(SetName, TestName)
{
    UNITTEST_ASSERT_FALSE(false);
}
```

At the top of the file we include the previously mentioned hypertest.cpp followed with the file with the functions
we want to test.

Then a test is declared using the `TEST` macro where the user specifies a name for the Set of tests the test belongs to as well
as a name for the test.

Within the brackets is the code that will be run for that individual unit test. Assertions are made using macros that are defined
in hypertest_asserts.h. For reference the different assert macros are listed bellow.

```C
UNITTEST_ASSERT(X, Y, Condition)
UNITTEST_ASSERT_TRUE(X)
UNITTEST_ASSERT_FALSE(X)
UNITTEST_ASSERT_EQUAL(X, Y)
UNITTEST_ASSERT_NOTEQUAL(X, Y)
UNITTEST_ASSERT_LESSTHAN(X, Y)
UNITTEST_ASSERT_LESSOREQUAL(X, Y)
UNITTEST_ASSERT_GREATERTHAN(X, Y)
UNITTEST_ASSERT_GREATEROREQUAL(X, Y)

UNITTEST_EXPECT(X, Y, Condition)
UNITTEST_EXPECT_TRUE(X)
UNITTEST_EXPECT_FALSE(X)
UNITTEST_EXPECT_EQUAL(X, Y)
UNITTEST_EXPECT_NOTEQUAL(X, Y)
UNITTEST_EXPECT_LESSTHAN(X, Y)
UNITTEST_EXPECT_LESSOREQUAL(X, Y)
UNITTEST_EXPECT_GREATERTHAN(X, Y)
UNITTEST_EXPECT_GREATEROREQUAL(X, Y)

UNITTEST_INVALID_PATH(Message)
```

The difference between the asserts and the expect macros are simply that an assert will stop execution of the test while an expect will not return from the test and continue execution as normal.

Personally I use bat scripts to compile my tests while other tools can be used as well with some tinkering. Using a bat file its as simple as the following:

```cmd
set CommonCompilerFlags=-nologo /Zi 
set CommonLinkerFlags=-incremental:no

cl %CommonCompilerFlags% -DBUILD_WINDOWS=1 -DBUILD_LINUX=0 -D_CRT_SECURE_NO_WARNINGS .\sample1_unittest.cpp /link %CommonLinkerFlags%
```

Use the flags `DBUILD_WINDOWS` and `DBUILD_LINUX` to state wether your building for win32 or linux.

Where CompilerFlags and LinkerFlags would be your flags sent to the compiler. cl has a list of compiler flags in their [Documentation](https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-alphabetically?view=vs-2019)

## Contributing

## How to test
