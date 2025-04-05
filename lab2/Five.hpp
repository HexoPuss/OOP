#ifndef FIVE_H
#define FIVE_H

#include <iostream>
#include <vector>
#include <string>

class Five {
private:
    std::vector<unsigned char> digits; // Цифры числа (младший разряд - первый)
    
    void removeLeadingZeros(); // Удаление незначащих нулей

public:
    // Конструкторы
    Five();
    Five(const size_t & n, unsigned char t = 0);
    Five(const std::initializer_list<unsigned char> &t);
    Five(const std::string &value);
    Five(const Five &other);
    Five(Five &&other);
    ~Five();
    
    // Операции присваивания
    Five &operator=(const Five &other);
    Five &operator=(Five &&other);
    
    // Арифметические операции
    Five operator+(const Five &other) const;
    Five operator-(const Five &other) const;
    
    // Операции сравнения
    bool operator==(const Five &other) const;
    bool operator<(const Five &other) const;
    bool operator>(const Five &other) const;

    // Ввод и вывод
    friend std::ostream &operator<<(std::ostream &out, const Five &num);
    friend std::istream &operator>>(std::istream &in, Five &num);
};

#endif // FIVE_H