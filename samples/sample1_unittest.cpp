#include "../code/hypertest.cpp"
#include "sample1.cpp"

#if BUILD_LINUX
#include <unistd.h>
#endif

TEST(IsPrimeTest, Negative)
{
    UNITTEST_ASSERT_FALSE(IsPrime(-1));
    UNITTEST_ASSERT_FALSE(IsPrime(-2));
    UNITTEST_ASSERT_FALSE(IsPrime((int32_t)0x80000000));
}

TEST(FailingTest, ThisShouldFail)
{
    UNITTEST_ASSERT_TRUE(IsPrime(0));
}

TEST(IsPrimeTest, Trivial)
{
    UNITTEST_ASSERT_FALSE(IsPrime(0));
    UNITTEST_ASSERT_FALSE(IsPrime(1));

    UNITTEST_ASSERT_TRUE(IsPrime(2));
    UNITTEST_ASSERT_TRUE(IsPrime(3));
}

TEST(Test, SomeName)
{
    UNITTEST_ASSERT_TRUE(1);
    UNITTEST_ASSERT_TRUE(2);
    UNITTEST_ASSERT_FALSE(0);
}

TEST(Timing, ShouldTakeFiveMilNs)
{
#if BUILD_WINDOWS
    Sleep(5);
#elif BUILD_LINUX
    sleep(5);
#endif
}