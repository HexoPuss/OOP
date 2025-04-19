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

    
    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
}

TEST(Hexagon, moveConstructor)
{
    Hexagon obj1;
    std::istringstream iStream("11 11 5");
    iStream >> obj1;
    Hexagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
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

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
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

    EXPECT_EQ(oStream.str(), "6-угольник: (11 ; 11)(13.5 ; 15.3301)(18.5 ; 15.3301)(21 ; 11)(18.5 ; 6.66987)(13.5 ; 6.66987)");
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

    EXPECT_EQ(stream.str(), "6-угольник: (0 ; 0)(2.5 ; 4.33013)(7.5 ; 4.33013)(10 ; 0)(7.5 ; -4.33013)(2.5 ; -4.33013)");
}

TEST(Hexagon, inputAndOutput)
{
    Hexagon obj;
    std::istringstream iStream("12.56 -32.44 10");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "6-угольник: (12.56 ; -32.44)(17.56 ; -23.7797)(27.56 ; -23.7797)(32.56 ; -32.44)(27.56 ; -41.1003)(17.56 ; -41.1003)");
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

    EXPECT_EQ(std::fabs(center.x - (10 + 15)) < EPS, true);
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

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -436.001)(6.08786 ; -440.703)(8.56 ; -440.703)(16.56 ; -440.703)(19.0321 ; -440.703)");
}

TEST(Pentagon, moveConstructor)
{
    Pentagon obj1;
    std::istringstream iStream("12.56 -32.44 12");
    iStream >> obj1;
    Pentagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -32.44)(2.8518 ; -39.4934)(6.56 ; -50.9061)(18.56 ; -50.9061)(22.2682 ; -39.4934)");
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

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -32.44)(7.7059 ; -35.9667)(9.56 ; -41.6731)(15.56 ; -41.6731)(17.4141 ; -35.9667)");
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

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -32.44)(8.51492 ; -35.3789)(10.06 ; -40.1342)(15.06 ; -40.1342)(16.6051 ; -35.3789)");
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

    EXPECT_EQ(stream.str(), "5-угольник: (0 ; 0)(-4.04508 ; -2.93893)(-2.5 ; -7.69421)(2.5 ; -7.69421)(4.04508 ; -2.93893)");
}

TEST(Pentagon, inputAndOutput)
{
    Pentagon obj;
    std::istringstream iStream("12.56 -32.44 15");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "5-угольник: (12.56 ; -32.44)(0.424745 ; -41.2568)(5.06 ; -55.5226)(20.06 ; -55.5226)(24.6953 ; -41.2568)");
}

TEST(Pentagon, area)
{
    Pentagon obj;
    std::istringstream iStream("78.2 0 8");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 110.111) < EPS, true);
}

TEST(Pentagon, center)
{
    Pentagon obj;
    std::istringstream iStream("100 200 20");
    iStream >> obj;
    auto center{obj.findCenter()};

    EXPECT_EQ(std::fabs(center.x - 100) < EPS, true);
    EXPECT_EQ(std::fabs(center.y - 182.987) < EPS, true);
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

    EXPECT_EQ(oStream.str(), "8-угольник: (-1.3 ; 9.43553)(-4.83553 ; 5.9)(-4.83553 ; 0.9)(-1.3 ; -2.63553)(3.7 ; -2.63553)(7.23553 ; 0.9)(7.23553 ; 5.9)(3.7 ; 9.43553)");
}

TEST(Octagon, moveConstructor)
{
    Octagon obj1;
    std::istringstream iStream("-1 -2 6");
    iStream >> obj1;
    Octagon obj2(std::move(obj1));
    std::ostringstream oStream;
    oStream << obj2;

    EXPECT_EQ(oStream.str(), "8-угольник: (-4 ; 5.24264)(-8.24264 ; 1)(-8.24264 ; -5)(-4 ; -9.24264)(2 ; -9.24264)(6.24264 ; -5)(6.24264 ; 1)(2 ; 5.24264)");
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

    EXPECT_EQ(oStream.str(), "8-угольник: (-5 ; 12.0711)(-12.0711 ; 5)(-12.0711 ; -5)(-5 ; -12.0711)(5 ; -12.0711)(12.0711 ; -5)(12.0711 ; 5)(5 ; 12.0711)");
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

    EXPECT_EQ(oStream.str(), "8-угольник: (0.46 ; 8.57198)(-2.72198 ; 5.39)(-2.72198 ; 0.89)(0.46 ; -2.29198)(4.96 ; -2.29198)(8.14198 ; 0.89)(8.14198 ; 5.39)(4.96 ; 8.57198)");
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

    EXPECT_EQ(stream.str(), "8-угольник: (-2.5 ; 6.03553)(-6.03553 ; 2.5)(-6.03553 ; -2.5)(-2.5 ; -6.03553)(2.5 ; -6.03553)(6.03553 ; -2.5)(6.03553 ; 2.5)(2.5 ; 6.03553)");
}

TEST(Octagon, inputAndOutput)
{
    Octagon obj;
    std::istringstream iStream("-2.5 -1.5 6.7");
    std::ostringstream oStream;
    iStream >> obj;
    oStream << obj;

    EXPECT_EQ(oStream.str(), "8-угольник: (-5.85 ; 6.58762)(-10.5876 ; 1.85)(-10.5876 ; -4.85)(-5.85 ; -9.58762)(0.85 ; -9.58762)(5.58762 ; -4.85)(5.58762 ; 1.85)(0.85 ; 6.58762)");
}

TEST(Octagon, area)
{
    Octagon obj;
    std::istringstream iStream("500.8 597.7 12.5");
    iStream >> obj;
    double area = static_cast<double>(obj);

    EXPECT_EQ(std::fabs(area - 754.442) < EPS, true);
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