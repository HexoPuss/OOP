#include <gtest/gtest.h>
#include <sstream>      // Для работы со строковыми потоками
#include "Five.hpp"     // Заголовок с классом Five



// Проверка конструктора по умолчанию
TEST(FiveTest, DefaultConstructor) {
    Five num;
    // Проверим, что число инициализировано нулём
    // В зависимости от того, как у вас устроено хранение
    // и вывод, далее можно корректно проверить.
    // Предположим, что по умолчанию получается "0".
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "0");
}

// Проверка конструктора из size_t и значения по умолчанию
TEST(FiveTest, ConstructorWithSizeT) {
    Five num(5, 2); // Создаём число из 5 разрядов, где каждый разряд = 7
    std::stringstream ss;
    ss << num;
    // Предположим, что 5 одинаковых цифр "7" означает "77777"
    // Но учтите, что в классе digits (младший разряд - первый),
    // при выводе должно получиться "77777". Проверим это:
    EXPECT_EQ(ss.str(), "22222");
}

// Проверка конструктора из initializer_list
TEST(FiveTest, InitializerListConstructor) {
    Five num = {1, 2, 3, 4};
    std::stringstream ss;
    ss << num;
    // digits хранится в порядке {4,3,2,1}, но выводим с бытовой точки зрения
    EXPECT_EQ(ss.str(), "1234");
}

// Проверка конструктора из строки
TEST(FiveTest, StringConstructor) {
    Five num("01234");
    std::stringstream ss;
    ss << num;
    // Если removeLeadingZeros корректно работает, должно получиться "12345"
    EXPECT_EQ(ss.str(), "1234");
}

// Проверка конструктора копирования
TEST(FiveTest, CopyConstructor) {
    Five original("2222");
    Five copy(original);
    EXPECT_EQ(original, copy);
}

// Проверка конструктора перемещения
TEST(FiveTest, MoveConstructor) {
    Five temp("3421");
    Five moved(std::move(temp));
    // Теперь moved должен содержать "888",
    // а temp может быть в каком-то корректном, но не определённом состоянии
    std::stringstream ss;
    ss << moved;
    EXPECT_EQ(ss.str(), "3421");
}

// Проверка оператора копирующего присваивания
TEST(FiveTest, CopyAssignment) {
    Five num1("123");
    Five num2("111");
    num2 = num1;
    EXPECT_EQ(num2, num1);
}

// Проверка оператора перемещающего присваивания
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
    // 12345 - 12300 = 45
    EXPECT_EQ(ss.str(), "41");
}

// Тест оператора == (равенство)
TEST(FiveTest, OperatorEqual) {
    Five num1("200");
    Five num2("0200");
    Five num3("201");
    EXPECT_TRUE(num1 == num2);  // "500" == "500"
    EXPECT_FALSE(num1 == num3); // "500" != "501"
}

// Тест оператора < (меньше)
TEST(FiveTest, OperatorLess) {
    Five num1("3444");
    Five num2("4000");
    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num2 < num1);
}

// Тест оператора > (больше)
TEST(FiveTest, OperatorGreater) {
    Five num1("400");
    Five num2("344");
    EXPECT_TRUE(num1 > num2);
    EXPECT_FALSE(num2 > num1);
}

// Тест операторов ввода/вывода
TEST(FiveTest, InputOutputOperators) {
    std::stringstream input("100");
    Five num;
    input >> num; // Чтение из потока
    std::stringstream output;
    output << num; // Запись в поток
    EXPECT_EQ(output.str(), "100");
}