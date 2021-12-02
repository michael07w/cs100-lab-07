#include "gtest/gtest.h"
#include <math.h>
#include "factory.hpp"

TEST(Operators, Addition) {
    Factory f;
    char* args[] = {"2", "+", "10"};
    int count = 3;

    Base* result = f.parse(args, count);
    EXPECT_EQ(result->evaluate(), 2 + 10);
}

TEST(Operators, Subtraction) {
    Factory f;
    char* args[] = {"54", "-", "11"};
    int count = 3;

    Base* result = f.parse(args,count);
    EXPECT_EQ(result->evaluate(), 54 - 11);
}

TEST(Operators, Multiplication) {
    Factory f;
    char* args[] = {"54", "*", "11"};
    int count = 3;

    Base* result = f.parse(args,count);
    EXPECT_EQ(result->evaluate(), 54 * 11);
}

TEST(Operators, Division) {
    Factory f;
    char* args[] = {"235", "/", "11"};
    int count = 3;

    Base* result = f.parse(args,count);
    EXPECT_DOUBLE_EQ(result->evaluate(), 235.0 / 11.0);
}

TEST(Operators, Power) {
    Factory f;
    char* args[] = {"5", "**", "3"};
    int count = 3;

    Base* result = f.parse(args, count);
    EXPECT_EQ(result->evaluate(), pow(5, 3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
