#include <gtest/gtest.h>
#include "heads/hexagon.hpp"
#include "heads/pentagon.hpp"
#include "heads/octagon.hpp"

// Hexagon

TEST(Hexagon, constructorAndDestructor)
{
    Figure *obj = new Hexagon;
    delete obj;
}
TEST(Hexagon, copyConstructor)
{
    Hexagon obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Шестиугольник: (11, 11), сторона: 5");
}
TEST(Hexagon, moveConstructor)
{
    Hexagon obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Шестиугольник: (11, 11), сторона: 5");
}
TEST(Hexagon, assignmentOperator)
{
    Hexagon obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Шестиугольник: (11, 11), сторона: 5");
}
TEST(Hexagon, moveAssignment)
{
    Hexagon obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Шестиугольник: (11, 11), сторона: 5");
}
TEST(Hexagon, equal)
{
    Hexagon obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    Hexagon obj3;
    std::istringstream iStream3("11 11 5");
    iStream3 >> obj3;

    EXPECT_EQ(obj1 == obj1, true);
    EXPECT_EQ(obj1 == obj2, false);
    EXPECT_EQ(obj1 == obj3, true);

    EXPECT_EQ(obj2 == obj1, false);
    EXPECT_EQ(obj2 == obj2, true);
    EXPECT_EQ(obj2 == obj3, false);

    EXPECT_EQ(obj3 == obj1, true);
    EXPECT_EQ(obj3 == obj2, false);
    EXPECT_EQ(obj3 == obj3, true);
}
TEST(Hexagon, notEqual)
{
    Hexagon obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    Hexagon obj3;
    std::istringstream iStream3("11 11 5");
    iStream3 >> obj3;

    EXPECT_EQ(obj1 != obj1, false);
    EXPECT_EQ(obj1 != obj2, true);
    EXPECT_EQ(obj1 != obj3, false);

    EXPECT_EQ(obj2 != obj1, true);
    EXPECT_EQ(obj2 != obj2, false);
    EXPECT_EQ(obj2 != obj3, true);

    EXPECT_EQ(obj3 != obj1, false);
    EXPECT_EQ(obj3 != obj2, true);
    EXPECT_EQ(obj3 != obj3, false);
}
TEST(Hexagon, defaultOutput)
{
    Hexagon obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "Шестиугольник: (0, 0), сторона: 0");
}
TEST(Hexagon, inputAndOutput)
{
    Hexagon obj;
    std::istringstream iStream("12.56 -32.44 10");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "Шестиугольник: (12.56, -32.44), сторона: 10");
}
TEST(Hexagon, area)
{
    Hexagon obj;
    std::istringstream iStream("11 11 5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 64.95191) < EPS, true);
}
TEST(Hexagon, center)
{
    Hexagon obj;
    std::istringstream iStream("10 20 15");
    iStream >> obj;
    auto center{obj.findCenter()};

    EXPECT_EQ(std::fabs(center.x - 10) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 20) < EPS, true);
}

// Pentagon

TEST(Pentagon, constructorAndDestructor)
{
    Figure *obj = new Pentagon;
    delete obj;
}
TEST(Pentagon, copyConstructor)
{
    Pentagon obj1;
    std::istringstream iStream("12.56 -436.001 8");
    iStream >> obj1;
    Pentagon obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Пятиугольник: (12.56, -436.001), сторона: 8");
}
TEST(Pentagon, moveConstructor)
{
    Pentagon obj1;
    std::istringstream iStream("12.56 -32.44 12");
    iStream >> obj1;
    Pentagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Пятиугольник: (12.56, -32.44), сторона: 12");
}
TEST(Pentagon, assignmentOperator)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -32.44 6");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 232 10");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Пятиугольник: (12.56, -32.44), сторона: 6");
}
TEST(Pentagon, moveAssignment)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -32.44 5");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 -6720 7");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Пятиугольник: (12.56, -32.44), сторона: 5");
}
TEST(Pentagon, equal)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -436.001 9");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 0 11");
    iStream2 >> obj2;
    Pentagon obj3;
    std::istringstream iStream3("12.56 -436.001 9");
    iStream3 >> obj3;

    EXPECT_EQ(obj1 == obj1, true);
    EXPECT_EQ(obj1 == obj2, false);
    EXPECT_EQ(obj1 == obj3, true);

    EXPECT_EQ(obj2 == obj1, false);
    EXPECT_EQ(obj2 == obj2, true);
    EXPECT_EQ(obj2 == obj3, false);

    EXPECT_EQ(obj3 == obj1, true);
    EXPECT_EQ(obj3 == obj2, false);
    EXPECT_EQ(obj3 == obj3, true);
}
TEST(Pentagon, notEqual)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -32.44 7");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 0 14");
    iStream2 >> obj2;
    Pentagon obj3;
    std::istringstream iStream3("12.56 -32.44 7");
    iStream3 >> obj3;

    EXPECT_EQ(obj1 != obj1, false);
    EXPECT_EQ(obj1 != obj2, true);
    EXPECT_EQ(obj1 != obj3, false);

    EXPECT_EQ(obj2 != obj1, true);
    EXPECT_EQ(obj2 != obj2, false);
    EXPECT_EQ(obj2 != obj3, true);

    EXPECT_EQ(obj3 != obj1, false);
    EXPECT_EQ(obj3 != obj2, true);
    EXPECT_EQ(obj3 != obj3, false);
}
TEST(Pentagon, defaultOutput)
{
    Pentagon obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "Пятиугольник: (0, 0), сторона: 0");
}
TEST(Pentagon, inputAndOutput)
{
    Pentagon obj;
    std::istringstream iStream("12.56 -32.44 15");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "Пятиугольник: (12.56, -32.44), сторона: 15");
}
TEST(Pentagon, area)
{
    Pentagon obj;
    std::istringstream iStream("78.2 0 8");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 110.85125) < EPS, true);
}
TEST(Pentagon, center)
{
    Pentagon obj;
    std::istringstream iStream("100 200 20");
    iStream >> obj;
    auto center{obj.findCenter()};

    EXPECT_EQ(std::fabs(center.x - 100) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 200) < EPS, true);
}

// Octagon

TEST(Octagon, constructorAndDestructor)
{
    Figure *obj = new Octagon;
    delete obj;
}
TEST(Octagon, copyConstructor)
{
    Octagon obj1;
    std::istringstream iStream("1.2 3.4 5");
    iStream >> obj1;
    Octagon obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Восьмиугольник: (1.2, 3.4), сторона: 5");
}
TEST(Octagon, moveConstructor)
{
    Octagon obj1;
    std::istringstream iStream("-1 -2 6");
    iStream >> obj1;
    Octagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Восьмиугольник: (-1, -2), сторона: 6");
}
TEST(Octagon, assignmentOperator)
{
    Octagon obj1;
    std::istringstream iStream1("0 0 10");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("-1 -2 3");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Восьмиугольник: (0, 0), сторона: 10");
}
TEST(Octagon, moveAssignment)
{
    Octagon obj1;
    std::istringstream iStream1("2.71 3.14 4.5");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("1.2 3.4 8");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "Восьмиугольник: (2.71, 3.14), сторона: 4.5");
}
TEST(Octagon, equal)
{
    Octagon obj1;
    std::istringstream iStream1("100 200 15");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("-0.5 0.5 7.5");
    iStream2 >> obj2;
    Octagon obj3;
    std::istringstream iStream3("100 200 15");
    iStream3 >> obj3;

    EXPECT_EQ(obj1 == obj1, true);
    EXPECT_EQ(obj1 == obj2, false);
    EXPECT_EQ(obj1 == obj3, true);

    EXPECT_EQ(obj2 == obj1, false);
    EXPECT_EQ(obj2 == obj2, true);
    EXPECT_EQ(obj2 == obj3, false);

    EXPECT_EQ(obj3 == obj1, true);
    EXPECT_EQ(obj3 == obj2, false);
    EXPECT_EQ(obj3 == obj3, true);
}

TEST(Octagon, notEqual)
{
    Octagon obj1;
    std::istringstream iStream1("5 1 9");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("0.1 0.2 4.3");
    iStream2 >> obj2;
    Octagon obj3;
    std::istringstream iStream3("5 1 9");
    iStream3 >> obj3;

    EXPECT_EQ(obj1 != obj1, false);
    EXPECT_EQ(obj1 != obj2, true);
    EXPECT_EQ(obj1 != obj3, false);

    EXPECT_EQ(obj2 != obj1, true);
    EXPECT_EQ(obj2 != obj2, false);
    EXPECT_EQ(obj2 != obj3, true);

    EXPECT_EQ(obj3 != obj1, false);
    EXPECT_EQ(obj3 != obj2, true);
    EXPECT_EQ(obj3 != obj3, false);
}
TEST(Octagon, defaultOutput)
{
    Octagon obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "Восьмиугольник: (0, 0), сторона: 0");
}
TEST(Octagon, inputAndOutput)
{
    Octagon obj;
    std::istringstream iStream("-2.5 -1.5 6.7");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "Восьмиугольник: (-2.5, -1.5), сторона: 6.7");
}
TEST(Octagon, area)
{
    Octagon obj;
    std::istringstream iStream("500.8 597.7 12.5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 482.84271) < EPS, true);
}
TEST(Octagon, center)
{
    Octagon obj;
    std::istringstream iStream("500.8 597.7 25");
    iStream >> obj;
    auto center{obj.findCenter()};

    EXPECT_EQ(std::fabs(center.x - 500.8) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 597.7) < EPS, true);
}