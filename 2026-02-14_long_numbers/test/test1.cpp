#include "long_number.hpp"
#include <gtest/gtest.h>

using NovSev::LongNumber;

TEST(LongNumberTest, Construction) {
    LongNumber a("12345");
    EXPECT_EQ(a, LongNumber("12345"));
}

TEST(LongNumberTest, NegativeCheck) {
    LongNumber b("-678");
    EXPECT_TRUE(b.is_negative());
}

TEST(LongNumberTest, Comparison_PosGreaterThanNeg) {
    LongNumber a("12345");
    LongNumber b("-678");
    EXPECT_TRUE(a > b);
}

TEST(LongNumberTest, Comparison_LargeNumbers) {
    EXPECT_TRUE(LongNumber("999999") > LongNumber("100000"));
}

TEST(LongNumberTest, Addition_999Plus1) {
    EXPECT_EQ(LongNumber("999") + LongNumber("1"), LongNumber("1000"));
}

TEST(LongNumberTest, Addition_WithNegative) {
    EXPECT_EQ(LongNumber("123") + LongNumber("-45"), LongNumber("78"));
}

TEST(LongNumberTest, Subtraction_1000Minus1) {
    EXPECT_EQ(LongNumber("1000") - LongNumber("1"), LongNumber("999"));
}

TEST(LongNumberTest, Subtraction_NegativeResult) {
    EXPECT_EQ(LongNumber("123") - LongNumber("456"), LongNumber("-333"));
}

TEST(LongNumberTest, Multiplication_Basic) {
    EXPECT_EQ(LongNumber("123") * LongNumber("45"), LongNumber("5535"));
}

TEST(LongNumberTest, Multiplication_Negative) {
    EXPECT_EQ(LongNumber("-12") * LongNumber("3"), LongNumber("-36"));
}

TEST(LongNumberTest, Division_Basic) {
    EXPECT_EQ(LongNumber("12345") / LongNumber("67"), LongNumber("184"));
}

TEST(LongNumberTest, Modulo_Basic) {
    EXPECT_EQ(LongNumber("12345") % LongNumber("67"), LongNumber("17"));
}

TEST(LongNumberTest, Identity_Positive) {
    LongNumber x("12345");
    LongNumber y("67");
    LongNumber q = x / y;
    LongNumber r = x % y;
    EXPECT_EQ((q * y + r), x);
}

TEST(LongNumberTest, Division_Negative) {
    EXPECT_EQ(LongNumber("-12345") / LongNumber("67"), LongNumber("-184"));
}

TEST(LongNumberTest, Modulo_Negative) {
    EXPECT_EQ(LongNumber("-12345") % LongNumber("67"), LongNumber("-17"));
}

TEST(LongNumberTest, Identity_Negative) {
    LongNumber neg("-12345");
    LongNumber pos("67");
    LongNumber qn = neg / pos;
    LongNumber rn = neg % pos;
    EXPECT_EQ((qn * pos + rn), neg);
}

TEST(LongNumberTest, ZeroArithmetic) {
    LongNumber zero("0");
    LongNumber a("12345");
    EXPECT_EQ(zero + a, a);
    EXPECT_EQ(a - a, zero);
    EXPECT_EQ(zero * a, zero);
}

TEST(LongNumberTest, DivisionByOne) {
    LongNumber a("12345");
    LongNumber one("1");
    EXPECT_EQ(a / one, a);
}

TEST(LongNumberTest, DivisionByZeroThrows) {
    LongNumber a("12345");
    LongNumber zero("0");
    EXPECT_THROW(a / zero, std::runtime_error);
}

TEST(LongNumberTest, BigNumber) {
    LongNumber big1("99999999999999999999");
    LongNumber big2("1");
    EXPECT_EQ(big1 + big2, LongNumber("100000000000000000000"));
}