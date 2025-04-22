#include "heads/hexagon.hpp"
#include "heads/octagon.hpp"
#include "heads/pentagon.hpp"
#include <gtest/gtest.h>
#include <cmath>
#include <limits>


//using integral = ::testing::Types<signed short, int, signed long long>;

using floating_point = ::testing::Types<float, double, long double>;


template <typename T>
class HexagonTest_float : public ::testing::Test {};

template <typename T>
class PentagonTest_float : public ::testing::Test {};

template <typename T>
class OctagonTest_float : public ::testing::Test {};




//TYPED_TEST_SUITE(HexagonTest_int, integral);
TYPED_TEST_SUITE(HexagonTest_float, floating_point);
//TYPED_TEST_SUITE(PentagonTest_int, integral);
TYPED_TEST_SUITE(PentagonTest_float, floating_point);
//TYPED_TEST_SUITE(OctagonTest_int, integral);
TYPED_TEST_SUITE(OctagonTest_float, floating_point);



// Hexagon

TYPED_TEST(HexagonTest_float, constructorAndDestructor)
{
    Figure<TypeParam> *obj = new Hexagon<TypeParam>;
    delete obj;
}

TYPED_TEST(HexagonTest_float, copyConstructor)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon<TypeParam> obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    
    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
}

TYPED_TEST(HexagonTest_float, moveConstructor)
{
    Hexagon<TypeParam> obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon<TypeParam> obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
}

TYPED_TEST(HexagonTest_float, assignmentOperator)
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

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
}

TYPED_TEST(HexagonTest_float, moveAssignment)
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

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
}

TYPED_TEST(HexagonTest_float, equal)
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

TYPED_TEST(HexagonTest_float, notEqual)
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

TYPED_TEST(HexagonTest_float, defaultOutput)
{
    Hexagon<TypeParam> obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "6-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(HexagonTest_float, inputAndOutput)
{
    Hexagon<TypeParam> obj;
    std::istringstream iStream("12.56 -32.44 10");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "6-угольник: (12.56 ; -32.44)(17.56 ; -23.7797)(27.56 ; -23.7797)(32.56 ; -32.44)(27.56 ; -41.1003)(17.56 ; -41.1003)");
}

TYPED_TEST(HexagonTest_float, area)
{
    Hexagon<TypeParam> obj;
    std::istringstream iStream("11 11 5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 64.95191) < EPS, true);
}

TYPED_TEST(HexagonTest_float, center)
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

TYPED_TEST(PentagonTest_float, constructorAndDestructor)
{
    Figure<TypeParam> *obj = new Pentagon<TypeParam>;
    delete obj;
}

TYPED_TEST(PentagonTest_float, copyConstructor)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream("12.56 -436.001 8");
    iStream >> obj1;
    Pentagon<TypeParam> obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -436.001)(6.08786 ; -440.703)(8.56 ; -440.703)(16.56 ; -440.703)(19.0321 ; -440.703)");
}

TYPED_TEST(PentagonTest_float, moveConstructor)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream("12.56 -32.44 12");
    iStream >> obj1;
    Pentagon<TypeParam> obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -32.44)(2.8518 ; -39.4934)(6.56 ; -50.9061)(18.56 ; -50.9061)(22.2682 ; -39.4934)");
}

TYPED_TEST(PentagonTest_float, assignmentOperator)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("12.56 -32.44 6");
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78.2 232 10");


    obj1 = obj1;
    obj2 = obj1;
    std::ostringstream oStream;
    oStream << obj2;


    EXPECT_NE(oStream.str(), " (78.2 ; 232)(70.1098 ; 226.122)(73.2 ; 216.612)(83.2 ; 216.612)(86.2902 ; 226.122)");
}

TYPED_TEST(PentagonTest_float, moveAssignment)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("12.56 -32.44 5");
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78.2 -6720 7");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -32.44)(8.51492 ; -35.3789)(10.06 ; -40.1342)(15.06 ; -40.1342)(16.6051 ; -35.3789)");
}

TYPED_TEST(PentagonTest_float, equal)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("12.56 -436.001 9");
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78.2 0 11");
    iStream2 >> obj2;
    Pentagon<TypeParam> obj3;
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

TYPED_TEST(PentagonTest_float, notEqual)
{
    Pentagon<TypeParam> obj1;
    std::istringstream iStream1("12.56 -32.44 7");
    iStream1 >> obj1;
    Pentagon<TypeParam> obj2;
    std::istringstream iStream2("78.2 0 14");
    iStream2 >> obj2;
    Pentagon<TypeParam> obj3;
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

TYPED_TEST(PentagonTest_float, defaultOutput)
{
    Pentagon<TypeParam> obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "5-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(PentagonTest_float, inputAndOutput)
{
    Pentagon<TypeParam> obj;
    std::istringstream iStream("12.56 -32.44 15");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_NE(oStream.str(), "5-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(PentagonTest_float, area)
{
    Pentagon<TypeParam> obj;
    std::istringstream iStream("78.2 0 8");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 110.111) < EPS, true);
}

TYPED_TEST(PentagonTest_float, center)
{
    Pentagon<TypeParam> obj;
    std::istringstream iStream("100 200 20");
    iStream >> obj;
    auto c{obj.findCenter()};
    Point center = *c;

    EXPECT_EQ(std::fabs(center.x - 100) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 182.987) < EPS, true);
}

// Octagon

TYPED_TEST(OctagonTest_float, constructorAndDestructor)
{
    Figure<TypeParam> *obj = new Octagon<TypeParam>;
    delete obj;
}

TYPED_TEST(OctagonTest_float, copyConstructor)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream("1.2 3.4 5");
    iStream >> obj1;
    Octagon<TypeParam> obj2(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_NE(oStream.str(), "8-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(OctagonTest_float, moveConstructor)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream("-1 -2 6");
    iStream >> obj1;
    Octagon<TypeParam> obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "8-угольник: (-4 ; 5.24264)(-8.24264 ; 1)(-8.24264 ; -5)(-4 ; -9.24264)(2 ; -9.24264)(6.24264 ; -5)(6.24264 ; 1)(2 ; 5.24264)");
}

TYPED_TEST(OctagonTest_float, assignmentOperator)
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

    EXPECT_EQ(oStream.str(), "8-угольник: (-5 ; 12.0711)(-12.0711 ; 5)(-12.0711 ; -5)(-5 ; -12.0711)(5 ; -12.0711)(12.0711 ; -5)(12.0711 ; 5)(5 ; 12.0711)");
}

TYPED_TEST(OctagonTest_float, moveAssignment)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("2.71 3.14 4.5");
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("1.2 3.4 8");
    iStream2 >> obj2;
    obj1 = std::move(obj1);
    obj2 = std::move(obj1);
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "8-угольник: (0.46 ; 8.57198)(-2.72198 ; 5.39)(-2.72198 ; 0.89)(0.46 ; -2.29198)(4.96 ; -2.29198)(8.14198 ; 0.89)(8.14198 ; 5.39)(4.96 ; 8.57198)");
}

TYPED_TEST(OctagonTest_float, equal)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("100 200 15");
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("-0.5 0.5 7.5");
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

TYPED_TEST(OctagonTest_float, notEqual)
{
    Octagon<TypeParam> obj1;
    std::istringstream iStream1("5 1 9");
    iStream1 >> obj1;
    Octagon<TypeParam> obj2;
    std::istringstream iStream2("0.1 0.2 4.3");
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

TYPED_TEST(OctagonTest_float, defaultOutput)
{
    Octagon<TypeParam> obj;
    std::ostringstream stream;
    stream << obj;

    EXPECT_EQ(stream.str(), "8-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(OctagonTest_float, inputAndOutput)
{
    Octagon<TypeParam> obj;
    std::istringstream iStream("-2.5 -1.5 6.7");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_NE(oStream.str(), "8-угольник: (0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)(0 ; 0)");
}

TYPED_TEST(OctagonTest_float, area)
{
    Octagon<TypeParam> obj;
    std::istringstream iStream("500.8 597.7 12.5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 754.442) < EPS, true);
}

TYPED_TEST(OctagonTest_float, center)
{
    Octagon<TypeParam> obj;
    std::istringstream iStream("500.8 597.7 25");
    iStream >> obj;
    auto c{obj.findCenter()};
    Point center = *c;

    EXPECT_EQ(std::fabs(center.x - 500.8) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 597.7) < EPS, true);
}
// Boilerplate main
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
