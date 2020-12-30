#include "../code/hypertest.cpp"
#include "sample1.cpp"

// NOTE(Oskar): Factorial Tests.
TEST(FactorialTest, Negative) {
  UNITTEST_EXPECT_EQUAL(1, Factorial(-5));
  UNITTEST_EXPECT_EQUAL(1, Factorial(-1));
  UNITTEST_EXPECT_GREATERTHAN(Factorial(-10), 0);
}

TEST(FactorialTest, Zero) {
  UNITTEST_EXPECT_EQUAL(1, Factorial(0));
}

TEST(FactorialTest, Positive) {
  UNITTEST_EXPECT_EQUAL(2, Factorial(1));
  UNITTEST_EXPECT_EQUAL(2, Factorial(2));
  UNITTEST_EXPECT_EQUAL(6, Factorial(3));
  UNITTEST_EXPECT_EQUAL(40320, Factorial(8));
}

// NOTE(Oskar): IsPrime Tests.
TEST(IsPrimeTest, Negative)
{
    UNITTEST_ASSERT_FALSE(IsPrime(-1));
    UNITTEST_ASSERT_FALSE(IsPrime(-2));
    UNITTEST_ASSERT_FALSE(IsPrime((int32_t)0x80000000));
}

TEST(IsPrimeTest, Trivial)
{
    UNITTEST_ASSERT_FALSE(IsPrime(0));
    UNITTEST_ASSERT_FALSE(IsPrime(1));

    UNITTEST_ASSERT_TRUE(IsPrime(2));
    UNITTEST_ASSERT_TRUE(IsPrime(3));
}

TEST(IsPrimeTest, Positive) {
  UNITTEST_EXPECT_FALSE(IsPrime(4));
  UNITTEST_EXPECT_TRUE(IsPrime(5));
  UNITTEST_EXPECT_FALSE(IsPrime(6));
  UNITTEST_EXPECT_TRUE(IsPrime(23));
}