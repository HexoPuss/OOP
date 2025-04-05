#include <gtest/gtest.h>
#include <sstream>
#include "lab1.hpp"


TEST(LabTest, NormString) {
    
    std::stringstream ss;
    std::string s = removeVowels("AAAPOPOPOPOPA___+=!@--AOIUggLNeeu");

    ss << s << std::endl;
    EXPECT_EQ(ss.str(), "PPPPPggLN");
}

TEST(LabTest, EmptyString) {
    
    std::stringstream ss;
    std::string s = removeVowels("");

    ss << s;
    EXPECT_EQ(ss.str(), "");
}