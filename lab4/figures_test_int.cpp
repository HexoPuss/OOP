#include "heads/hexagon.hpp"
#include "heads/octagon.hpp"
#include "heads/pentagon.hpp"
#include <gtest/gtest.h>
#include <cmath>
#include <limits>


using integral = ::testing::Types<signed short, int, signed long long>;

//using int = ::testing::Types<float, double, long double>;


template <typename T>
class HexagonTest_int : public ::testing::Test {};

template <typename T>
class PentagonTest_int : public ::testing::Test {};

template <typename T>
class OctagonTest_int : public ::testing::Test {};




//TYPED_TEST_SUITE(HexagonTest_int, integral);
TYPED_TEST_SUITE(HexagonTest_int, integral);
//TYPED_TEST_SUITE(PentagonTest_int, integral);
TYPED_TEST_SUITE(PentagonTest_int, integral);
//TYPED_TEST_SUITE(OctagonTest_int, integral);
TYPED_TEST_SUITE(OctagonTest_int, integral);



// Hexagon

TYPED_TEST(HexagonTest_int, constructorAndDestructor)
{
    Figure<TypeParam> *obj = new Hexagon<TypeParam>;
    delete obj;
}

TYPED_TEST(HexagonTest_int, copyConstructor)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon<TypeParam> obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    
    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13 ; 15)(18 ; 15)(20 ; 10)(17 ; 5)(12 ; 5)");
}

TYPED_TEST(HexagonTest_int, moveConstructor)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon<TypeParam> obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13 ; 15)(18 ; 15)(20 ; 10)(17 ; 5)(12 ; 5)");
}

TYPED_TEST(HexagonTest_int, assignmentOperator)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon<TypeParam> obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13 ; 15)(18 ; 15)(20 ; 10)(17 ; 5)(12 ; 5)");
}

TYPED_TEST(HexagonTest_int, moveAssignment)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon<TypeParam> obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13 ; 15)(18 ; 15)(20 ; 10)(17 ; 5)(12 ; 5)");
}

TYPED_TEST(HexagonTest_int, equal)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon<TypeParam> obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    Hexagon<TypeParam> obj3;
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

TYPED_TEST(HexagonTest_int, notEqual)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream1("11 11 5");
    iStream1 >> obj1;
    Hexagon<TypeParam> obj2;
    std::istringstream iStream2("2 2 7");
    iStream2 >> obj2;
    Hexagon<TypeParam> obj3;
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

TYPED_TEST(HexagonTest_int, defaultOutput)
{
    Hexagon<TypeParam> obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "6-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(HexagonTest_int, inputAndOutput)
{
    Hexagon<TypeParam> obj;
    std::istringstream iStream("13 -32 10"); // 12.56 -> 13, -32.44 -> -32
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "6-угольник: (13 ; -32)(18 ; -23)(28 ; -23)(33 ; -31)(28 ; -39)(18 ; -39)");
}

TYPED_TEST(HexagonTest_int, area)
{
    Hexagon<TypeParam> obj;
    std::istringstream iStream("11 11 5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 64.95191) < EPS, true);
}

TYPED_TEST(HexagonTest_int, center)
{
    Hexagon<TypeParam> obj;
    std::istringstream iStream("10 20 15");
    iStream >> obj;
    auto c{obj.findCenter()};
    Point center = *c;

    EXPECT_EQ(std::fabs(center.x - (10 + 15)) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 20) < EPS, true);
}

// Pentagon

TYPED_TEST(PentagonTest_int, constructorAndDestructor)
{
    Figure<TypeParam> *obj = new Pentagon<TypeParam>;
    delete obj;
}

TYPED_TEST(PentagonTest_int, copyConstructor)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream("13 -436 8"); // 12.56 -> 13, -436.001 -> -436
    iStream >> obj1;
    Pentagon<TypeParam> obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (13 ; -436)(6 ; -440)(8 ; -440)(16 ; -440)(18 ; -440)");
}

TYPED_TEST(PentagonTest_int, moveConstructor)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream("13 -32 12"); // 12.56 -> 13, -32.44 -> -32
    iStream >> obj1;
    Pentagon<TypeParam> obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (13 ; -32)(3 ; -39)(6 ; -50)(18 ; -50)(21 ; -38)");
}

TYPED_TEST(PentagonTest_int, assignmentOperator)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("13 -32 6"); // 12.56 -> 13, -32.44 -> -32
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("0 0 0"); // 78.2 -> 78


    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;


    EXPECT_NE(oStream.str(), "5-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(PentagonTest_int, moveAssignment)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("13 -32 5"); // 12.56 -> 13, -32.44 -> -32
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78 -6720 7"); // 78.2 -> 78
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (13 ; -32)(8 ; -34)(9 ; -38)(14 ; -38)(15 ; -33)");
}

TYPED_TEST(PentagonTest_int, equal)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("13 -436 9"); // 12.56 -> 13, -436.001 -> -436
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78 0 11"); // 78.2 -> 78
    iStream2 >> obj2;
    Pentagon<TypeParam> obj3;
    std::istringstream iStream3("13 -436 9");
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

TYPED_TEST(PentagonTest_int, notEqual)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("13 -32 7");
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78 0 14");
    iStream2 >> obj2;
    Pentagon<TypeParam> obj3;
    std::istringstream iStream3("13 -32 7");
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

TYPED_TEST(PentagonTest_int, defaultOutput)
{
    Pentagon<TypeParam> obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "5-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(PentagonTest_int, inputAndOutput)
{
    Pentagon<TypeParam> obj;
    std::istringstream iStream("13 -32 15");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_NE(oStream.str(), "5-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(PentagonTest_int, area)
{
    Pentagon<TypeParam> obj;
    std::istringstream iStream("78 0 8");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 110.111) < EPS, true);
    
}

TYPED_TEST(PentagonTest_int, center)
{
    Pentagon<TypeParam> obj;
    std::istringstream iStream("100 200 20");
    iStream >> obj;
    auto c{obj.findCenter()};
    Point center = *c;

    EXPECT_EQ(std::fabs(center.x - 100) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 182) < EPS, true);
    
}

// Octagon

TYPED_TEST(OctagonTest_int, constructorAndDestructor)
{
    Figure<TypeParam> *obj = new Octagon<TypeParam>;
    delete obj;
}

TYPED_TEST(OctagonTest_int, copyConstructor)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream("1 3 5"); // 1.2 -> 1, 3.4 -> 3
    iStream >> obj1;
    Octagon<TypeParam> obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_NE(oStream.str(), "8-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(OctagonTest_int, moveConstructor)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream("-1 -2 6");
    iStream >> obj1;
    Octagon<TypeParam> obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "8-угольник: (-4 ; 5)(-8 ; 0)(-8 ; -6)(-3 ; -10)(3 ; -10)(7 ; -5)(7 ; 1)(2 ; 5)");
}

TYPED_TEST(OctagonTest_int, assignmentOperator)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("0 0 10");
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("-1 -2 3");
    iStream2 >> obj2;
    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "8-угольник: (-5 ; 12)(-12 ; 4)(-12 ; -6)(-4 ; -13)(6 ; -13)(13 ; -5)(13 ; 5)(5 ; 12)");
}

TYPED_TEST(OctagonTest_int, moveAssignment)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("3 3 5"); // 2.71 -> 3, 3.14 -> 3, 4.5 -> 5
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("1 3 8"); // 1.2 -> 1, 3.4 -> 3
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "8-угольник: (0 ; 9)(-3 ; 5)(-3 ; 0)(0 ; -3)(5 ; -3)(8 ; 0)(8 ; 5)(4 ; 8)");
}

TYPED_TEST(OctagonTest_int, equal)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("100 200 15");
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("-1 1 8"); // -0.5 -> -1, 0.5 -> 1, 7.5 -> 8
    iStream2 >> obj2;
    Octagon<TypeParam> obj3;
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

TYPED_TEST(OctagonTest_int, notEqual)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("5 1 9");
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("0 0 4"); // 0.1 -> 0, 0.2 -> 0, 4.3 -> 4
    iStream2 >> obj2;
    Octagon<TypeParam> obj3;
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

TYPED_TEST(OctagonTest_int, defaultOutput)
{
    Octagon<TypeParam> obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "8-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(OctagonTest_int, inputAndOutput)
{
    Octagon<TypeParam> obj;
    std::istringstream iStream("-2 -2 7"); // -2.5 -> -2, -1.5 -> -2, 6.7 -> 7
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_NE(oStream.str(), "8-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(OctagonTest_int, area)
{
    Octagon<TypeParam> obj;
    std::istringstream iStream("501 598 13"); // 500.8 -> 501, 597.7 -> 598, 12.5 -> 13
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 816.004) < EPS, true);
    
}

TYPED_TEST(OctagonTest_int, center)
{
    Octagon<TypeParam> obj;
    std::istringstream iStream("501 598 25"); // 500.8 -> 501, 597.7 -> 598
    iStream >> obj;
    auto c{obj.findCenter()};
    Point center = *c;

    EXPECT_EQ(std::fabs(center.x - 501) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 598) < EPS, true);
}
// Boilerplate main
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
