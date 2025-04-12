#include <gtest/gtest.h>
#include <sstream>      
#include "Five.hpp"     




TEST(FiveTest, DefaultConstructor) {
    Five num;
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "0");
}


TEST(FiveTest, ConstructorWithSizeT) {
    Five num(5, 2);
    std::stringstream ss;
    ss << num;
    
    EXPECT_EQ(ss.str(), "22222");
}

TEST(FiveTest, InitializerListConstructor) {
    Five num = {1, 2, 3, 4};
    std::stringstream ss;
    ss << num;
    
    EXPECT_EQ(ss.str(), "1234");
}


TEST(FiveTest, StringConstructor) {
    Five num("01234");
    std::stringstream ss;
    ss << num;
    
    EXPECT_EQ(ss.str(), "1234");
}


TEST(FiveTest, CopyConstructor) {
    Five original("2222");
    Five copy(original);
    EXPECT_EQ(original, copy);
}


TEST(FiveTest, MoveConstructor) {
    Five temp("3421");
    Five moved(std::move(temp));
    
    std::stringstream ss;
    ss << moved;
    EXPECT_EQ(ss.str(), "3421");
}


TEST(FiveTest, CopyAssignment) {
    Five num1("123");
    Five num2("111");
    num2 = num1;
    EXPECT_EQ(num2, num1);
}


TEST(FiveTest, MoveAssignment) {
    Five num1("441");
    Five num2("111");
    num2 = std::move(num1);
    std::stringstream ss;
    ss << num2;
    EXPECT_EQ(ss.str(), "441");
}

// Тест оператора +
TEST(FiveTest, OperatorPlus) {
    Five num1("24");
    Five num2("44421");
    Five result = num1 + num2;
    std::stringstream ss;
    ss << result;
    
    EXPECT_EQ(ss.str(), "100000");
}

// Тест оператора -
TEST(FiveTest, OperatorMinus) {
    Five num1("12341");
    Five num2("12300");
    Five result = num1 - num2;
    std::stringstream ss;
    ss << result;
    
    EXPECT_EQ(ss.str(), "41");
}

// Тест оператора == (равенство)
TEST(FiveTest, OperatorEqual) {
    Five num1("200");
    Five num2("0200");
    Five num3("201");
    EXPECT_TRUE(num1 == num2); 
    EXPECT_FALSE(num1 == num3); 
}

TEST(FiveTest, OperatorLess) {
    Five num1("3444");
    Five num2("4000");
    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num2 < num1);
}

TEST(FiveTest, OperatorGreater) {
    Five num1("400");
    Five num2("344");
    EXPECT_TRUE(num1 > num2);
    EXPECT_FALSE(num2 > num1);
}

TEST(FiveTest, InputOutputOperators) {
    std::stringstream input("100");
    Five num;
    input >> num; 
    std::stringstream output;
    output << num; 
    EXPECT_EQ(output.str(), "100");
}