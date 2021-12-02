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

TEST(FacTest, PowZero) {
    Factory f;
    char* args[] = {"5", "**", "0"};
    int count = 3;

    Base* result = f.parse(args, count);
    EXPECT_EQ(result->evaluate(), 1);
}

TEST(FacTest, InvalidInput) {
    Factory f;
    char* args[] = {"5", "+", "3", "*"};
    int count = 2;

    Base* result = f.parse(args, count);
    EXPECT_EQ(result, nullptr);
}

TEST(FacTest,DoubleOutput) {
   Factory f;
   char* args[] = {"2.1", "-", "3.5"};
   int count = 3;

   Base* result = f.parse(args, count);
   EXPECT_NEAR(result->evaluate(), -1.4, 0.1);
} 

TEST(FacTest,IncorrectPEMDAS) {
   Factory f;
   char* args[] = {"3", "+", "2", "*", "6"};
   int count = 5;

   Base* result = f.parse(args, count);
   EXPECT_EQ(result->evaluate(), 30);
}

TEST(MultOpTest, MultDiv) {
   Factory f;
   char* args[] = {"6", "/", "2", "*", "3"};
   int count = 5;

   Base* result = f.parse(args, count);
   EXPECT_EQ(result->evaluate(), 9);
}

TEST(MultOpTest, SubMult) {
   Factory f;
   char* args[] = {"3", "-", "2", "*", "6"};
   int count = 5;
    
   Base* result = f.parse(args, count);
   EXPECT_EQ(result->evaluate(), 6);
}

TEST(MultOpTest, AddDiv) {
   Factory f;
   char* args[] = {"3", "+", "3", "/", "6"};
   int count = 5;
    
   Base* result = f.parse(args, count);
   EXPECT_EQ(result->evaluate(), 1);
}

TEST(MultOpTest, AllOp) {
   Factory f;
   char* args[] = {"3", "**", "2", "*", "6", "/", "9", "+", "4", "-", "10"};
   int count = 11;
    
   Base* result = f.parse(args, count);
   EXPECT_EQ(result->evaluate(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
