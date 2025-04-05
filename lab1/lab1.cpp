#include <iostream>
#include <string>
#include "lab1.hpp"


bool isVowel(char c) {
    
    const std::string vowels = "aeiouAEIOU"; 
    return vowels.find(c) != std::string::npos;
}


std::string removeVowels(std::string input) {
    std::string result;
    
    for (char c : input) {
        if (!isVowel(c)) {
            result.push_back(c);
        }
    }
    return result;
}

