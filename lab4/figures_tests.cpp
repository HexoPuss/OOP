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

    ASSERT_EQ(oStream.str(), "Квадрат: (12.56, -32.44), (133.1, -32.44), (133.1, 88.1), (12.56, 88.1).");
}
TEST(Hexagon, moveConstructor)
{
    Hexagon obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Квадрат: (12.56, -32.44), (133.1, -32.44), (133.1, 88.1), (12.56, 88.1).");
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

    ASSERT_EQ(oStream.str(), "Квадрат: (12.56, -32.44), (133.1, -32.44), (133.1, 88.1), (12.56, 88.1).");
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

    ASSERT_EQ(oStream.str(), "Квадрат: (12.56, -32.44), (133.1, -32.44), (133.1, 88.1), (12.56, 88.1).");
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

    ASSERT_EQ(obj1 == obj1, true);
    ASSERT_EQ(obj1 == obj2, false);
    ASSERT_EQ(obj1 == obj3, true);

    ASSERT_EQ(obj2 == obj1, false);
    ASSERT_EQ(obj2 == obj2, true);
    ASSERT_EQ(obj2 == obj3, false);

    ASSERT_EQ(obj3 == obj1, true);
    ASSERT_EQ(obj3 == obj2, false);
    ASSERT_EQ(obj3 == obj3, true);
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

    ASSERT_EQ(obj1 != obj1, false);
    ASSERT_EQ(obj1 != obj2, true);
    ASSERT_EQ(obj1 != obj3, false);

    ASSERT_EQ(obj2 != obj1, true);
    ASSERT_EQ(obj2 != obj2, false);
    ASSERT_EQ(obj2 != obj3, true);

    ASSERT_EQ(obj3 != obj1, false);
    ASSERT_EQ(obj3 != obj2, true);
    ASSERT_EQ(obj3 != obj3, false);
}
TEST(Hexagon, defaultOutput)
{
    Hexagon obj;
    std::ostringstream stream;
    stream << obj;

    ASSERT_EQ(stream.str(), "Квадрат: (0, 0), (0, 0), (0, 0), (0, 0).");
}
TEST(Hexagon, inputAndOutput)
{
    Hexagon obj;
    std::istringstream iStream("12.56 -32.44 133.1 88.1");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    ASSERT_EQ(oStream.str(), "Квадрат: (12.56, -32.44), (133.1, -32.44), (133.1, 88.1), (12.56, 88.1).");
}
TEST(Hexagon, area)
{
    Hexagon obj;
    std::istringstream iStream("11 11 5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    ASSERT_EQ(std::fabs(area - 64.95191) < EPS, true);
}
TEST(Hexagon, center)
{
    Hexagon obj;
    std::istringstream iStream("-81.01 721 892.0 -252.01");
    iStream >> obj;
    auto center{obj.findCenter()};

    ASSERT_EQ(std::fabs(center.x - 405.495) < EPS, true);
    ASSERT_EQ(std::fabs(center.y - 234.495) < EPS, true);
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
    std::istringstream iStream("12.56 -436.001 133.1 88.1");
    iStream >> obj1;
    Pentagon obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Прямоугольник: (12.56, -436.001), (133.1, -436.001), (133.1, 88.1), (12.56, 88.1).");
}
TEST(Pentagon, moveConstructor)
{
    Pentagon obj1;
    std::istringstream iStream("12.56 -32.44 133.1 561.9");
    iStream >> obj1;
    Pentagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Прямоугольник: (12.56, -32.44), (133.1, -32.44), (133.1, 561.9), (12.56, 561.9).");
}
TEST(Pentagon, assignmentOperator)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -32.44 133.1 561.9");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 232 -23 101.2");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Прямоугольник: (12.56, -32.44), (133.1, -32.44), (133.1, 561.9), (12.56, 561.9).");
}
TEST(Pentagon, moveAssignment)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -32.44 133.1 561.9");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 -6720 -23 101.2");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Прямоугольник: (12.56, -32.44), (133.1, -32.44), (133.1, 561.9), (12.56, 561.9).");
}
TEST(Pentagon, equal)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -436.001 133.1 88.1");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 0 -23 99.23");
    iStream2 >> obj2;
    Pentagon obj3;
    std::istringstream iStream3("12.56 -436.001 133.1 88.1");
    iStream3 >> obj3;

    ASSERT_EQ(obj1 == obj1, true);
    ASSERT_EQ(obj1 == obj2, false);
    ASSERT_EQ(obj1 == obj3, true);

    ASSERT_EQ(obj2 == obj1, false);
    ASSERT_EQ(obj2 == obj2, true);
    ASSERT_EQ(obj2 == obj3, false);

    ASSERT_EQ(obj3 == obj1, true);
    ASSERT_EQ(obj3 == obj2, false);
    ASSERT_EQ(obj3 == obj3, true);
}
TEST(Pentagon, notEqual)
{
    Pentagon obj1;
    std::istringstream iStream1("12.56 -32.44 133.1 561.9");
    iStream1 >> obj1;
    Pentagon obj2;
    std::istringstream iStream2("78.2 0 -342 101.2");
    iStream2 >> obj2;
    Pentagon obj3;
    std::istringstream iStream3("12.56 -32.44 133.1 561.9");
    iStream3 >> obj3;

    ASSERT_EQ(obj1 != obj1, false);
    ASSERT_EQ(obj1 != obj2, true);
    ASSERT_EQ(obj1 != obj3, false);

    ASSERT_EQ(obj2 != obj1, true);
    ASSERT_EQ(obj2 != obj2, false);
    ASSERT_EQ(obj2 != obj3, true);

    ASSERT_EQ(obj3 != obj1, false);
    ASSERT_EQ(obj3 != obj2, true);
    ASSERT_EQ(obj3 != obj3, false);
}
TEST(Pentagon, defaultOutput)
{
    Pentagon obj;
    std::ostringstream stream;
    stream << obj;

    ASSERT_EQ(stream.str(), "Прямоугольник: (0, 0), (0, 0), (0, 0), (0, 0).");
}
TEST(Pentagon, inputAndOutput)
{
    Pentagon obj;
    std::istringstream iStream("12.56 -32.44 133.1 561.9");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    ASSERT_EQ(oStream.str(), "Прямоугольник: (12.56, -32.44), (133.1, -32.44), (133.1, 561.9), (12.56, 561.9).");
}
TEST(Pentagon, area)
{
    Pentagon obj;
    std::istringstream iStream("78.2 0 -23 101.2");
    iStream >> obj;
    double area = static_cast<double>(obj);

    ASSERT_EQ(std::fabs(area - 10241.44) < EPS, true);
}
TEST(Pentagon, center)
{
    Pentagon obj;
    std::istringstream iStream("-81.01 721 892.0 -346.566");
    iStream >> obj;
    auto center{obj.findCenter()};

    ASSERT_EQ(std::fabs(center.x - 405.495) < EPS, true);
    ASSERT_EQ(std::fabs(center.y - 187.217) < EPS, true);
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
    std::istringstream iStream("1.2 3.4 5.6 7.8 9.0 1.2 3.4 5.6");
    iStream >> obj1;
    Octagon obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Трапеция: (1.2, 3.4), (3.4, 5.6), (5.6, 7.8), (9, 1.2).");
}
TEST(Octagon, moveConstructor)
{
    Octagon obj1;
    std::istringstream iStream("-1 -2 3 4 -5 -6 7 8");
    iStream >> obj1;
    Octagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Трапеция: (-5, -6), (-1, -2), (3, 4), (7, 8).");
}
TEST(Octagon, assignmentOperator)
{
    Octagon obj1;
    std::istringstream iStream1("0 0 10 0 8 5 2 5");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("-1 -2 3 4 -5 -6 7 8");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Трапеция: (0, 0), (2, 5), (8, 5), (10, 0).");
}
TEST(Octagon, moveAssignment)
{
    Octagon obj1;
    std::istringstream iStream1("2.71 3.14 1.61 0.42 7.32 2.23 4.66 9.37");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("1.2 3.4 5.6 7.8 9.0 1.2 3.4 5.6");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    ASSERT_EQ(oStream.str(), "Трапеция: (1.61, 0.42), (2.71, 3.14), (4.66, 9.37), (7.32, 2.23).");
}
TEST(Octagon, equal)
{
    Octagon obj1;
    std::istringstream iStream1("100 200 150 200 125 175 75 175");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("-0.5 0.5 0 0 -0.25 -0.25 -0.75 -0.25");
    iStream2 >> obj2;
    Octagon obj3;
    std::istringstream iStream3("100 200 150 200 125 175 75 175");
    iStream3 >> obj3;

    ASSERT_EQ(obj1 == obj1, true);
    ASSERT_EQ(obj1 == obj2, false);
    ASSERT_EQ(obj1 == obj3, true);

    ASSERT_EQ(obj2 == obj1, false);
    ASSERT_EQ(obj2 == obj2, true);
    ASSERT_EQ(obj2 == obj3, false);

    ASSERT_EQ(obj3 == obj1, true);
    ASSERT_EQ(obj3 == obj2, false);
    ASSERT_EQ(obj3 == obj3, true);
}
TEST(Octagon, notEqual)
{
    Octagon obj1;
    std::istringstream iStream1("5 1 6 3 4 3 2 1");
    iStream1 >> obj1;
    Octagon obj2;
    std::istringstream iStream2("0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8");
    iStream2 >> obj2;
    Octagon obj3;
    std::istringstream iStream3("5 1 6 3 4 3 2 1");
    iStream3 >> obj3;

    ASSERT_EQ(obj1 != obj1, false);
    ASSERT_EQ(obj1 != obj2, true);
    ASSERT_EQ(obj1 != obj3, false);

    ASSERT_EQ(obj2 != obj1, true);
    ASSERT_EQ(obj2 != obj2, false);
    ASSERT_EQ(obj2 != obj3, true);

    ASSERT_EQ(obj3 != obj1, false);
    ASSERT_EQ(obj3 != obj2, true);
    ASSERT_EQ(obj3 != obj3, false);
}
TEST(Octagon, defaultOutput)
{
    Octagon obj;
    std::ostringstream stream;
    stream << obj;

    ASSERT_EQ(stream.str(), "Трапеция: (0, 0), (0, 0), (0, 0), (0, 0).");
}
TEST(Octagon, inputAndOutput)
{
    Octagon obj;
    std::istringstream iStream("-2.5 -1.5 0.5 1.5 2.5 1.5 -0.5 -1.5");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    ASSERT_EQ(oStream.str(), "Трапеция: (-2.5, -1.5), (-0.5, -1.5), (0.5, 1.5), (2.5, 1.5).");
}
TEST(Octagon, area)
{
    Octagon obj;
    std::istringstream iStream("500.8 597.7 600.73 597.7 550.34 551.055 525 551.055");
    iStream >> obj;
    double area = static_cast<double>(obj);

    ASSERT_EQ(std::fabs(area - 2921.6095750000068) < EPS, true);
}
TEST(Octagon, center)
{
    Octagon obj;
    std::istringstream iStream("500.8 597.7 600.73 597.7 550.34 551.055 525 551.055");
    iStream >> obj;
    auto center{obj.findCenter()};

    ASSERT_EQ(std::fabs(center.x - 541.61843118863248) < EPS, true);
    ASSERT_EQ(std::fabs(center.y - 565.11949582235695) < EPS, true);
}