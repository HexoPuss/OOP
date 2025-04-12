#include <gtest/gtest.h>
#include <sstream>
#include "lab1.hpp"


TEST(LabTest, NormString) {
    
    std::stringstream ss;
    std::string s = removeVowels("AAAPOPOPOPOPA___+=!@--AOIUggLNeeu");

    ss << s;
    EXPECT_EQ(ss.str(), "PPPPP___+=!@--ggLN");
}

TEST(LabTest, EmptyString) {
    
    std::stringstream ss;
    std::string s = removeVowels("");

    ss << s;
    EXPECT_EQ(ss.str(), "");
}

TEST(LabTest, VowelssString) {
    
    std::stringstream ss;
    std::string s = removeVowels("AAAuuUE");

    ss << s;
    EXPECT_EQ(ss.str(), "");
}