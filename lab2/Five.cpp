#include "Five.hpp"


void Five::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}

Five::Five(const size_t & n, unsigned char t) {
    
    if (t >= 5 || t < 0) {
        throw std::invalid_argument("Цифра t должна быть меньше 5 и больше 0.");
    }
    if (n == 0) {
        
        digits.push_back(0);
    } else {
        
        digits.assign(n, t);
    }
}


Five::Five(const std::initializer_list<unsigned char> & t) {
    if (t.size() == 0) {
        
        digits.push_back(0);
    } else {
        for (auto it = t.end(); it != t.begin(); ) {
            --it;
            if (*it >= 5) {
                throw std::invalid_argument("В списке инициализации обнаружена цифра, не подходящая для пятеричной системы.");
            }
            digits.push_back(*it);
        }
    }
}


Five::Five() : digits(1, 0) {}


Five::Five(const std::string &value) {
    if (value.empty()) {
        throw std::invalid_argument("Пустая строка недопустима");
    }
    digits.clear();
    
    for (auto it = value.rbegin(); it != value.rend(); ++it) {
        if (*it < '0' || *it > '4') {
            throw std::invalid_argument("Недопустимый символ в пятеричном числе");
        }
        digits.push_back(*it - '0');
    }
    removeLeadingZeros();
}


Five::Five(const Five &other) : digits(other.digits) {}


Five::Five(Five &&other) : digits(std::move(other.digits)) {}


Five::~Five() {}


Five &Five::operator=(const Five &other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}


Five &Five::operator=(Five &&other){
    if (this != &other) {
        digits = std::move(other.digits);
    }
    return *this;
}


Five Five::operator+(const Five &other) const {
    Five result;
    result.digits.clear();

    size_t maxSize = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;

    for (size_t i = 0; i < maxSize || carry; i++) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];

        result.digits.push_back(sum % 5);
        carry = sum / 5;
    }
    result.removeLeadingZeros();
    return result;
}


Five Five::operator-(const Five &other) const {
    
    if (*this < other) {
        throw std::underflow_error("Отрицательный результат в беззнаковом типе");
    }

    Five result;
    result.digits.clear();

    unsigned char borrow = 0;

    
    for (size_t i = 0; i < digits.size(); i++) {
        int sub = digits[i] - borrow;
        if (i < other.digits.size()) {
            sub -= other.digits[i];
        }
        if (sub < 0) {
            sub += 5;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits.push_back((unsigned char)(sub));
    }
    result.removeLeadingZeros();
    return result;
}


bool Five::operator==(const Five &other) const {
    
    size_t len1 = digits.size();
    while (len1 > 1 && digits[len1 - 1] == 0) {
        --len1;
    }
    size_t len2 = other.digits.size();
    while (len2 > 1 && other.digits[len2 - 1] == 0) {
        --len2;
    }
    if (len1 != len2) {
        return false;
    }
    for (size_t i = 0; i < len1; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}


bool Five::operator<(const Five &other) const {
    size_t len1 = digits.size();
    while (len1 > 1 && digits[len1 - 1] == 0) {
        --len1;
    }
    size_t len2 = other.digits.size();
    while (len2 > 1 && other.digits[len2 - 1] == 0) {
        --len2;
    }
    if (len1 != len2) {
        return len1 < len2;
    }
    
    for (size_t i = len1; i > 0; --i) {
        if (digits[i - 1] != other.digits[i - 1]) {
            return digits[i - 1] < other.digits[i - 1];
        }
    }
    return false;
}


bool Five::operator>(const Five &other) const {
    if(other == *this){
        return false;
    }
    return other < *this;
}


std::ostream &operator<<(std::ostream &out, const Five &num) {
    for (int i = num.digits.size(); i > 0; --i) {
        out << (char)(num.digits[i - 1] + '0');
    }
    return out;
}


std::istream &operator>>(std::istream &in, Five &num) {
    std::string input;
    in >> input;
    num = Five(input);
    return in;
}