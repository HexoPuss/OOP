#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <array>
#include <cmath>
#define EPS 0.001
#ifndef POINT_AND_FIGURE
#define POINT_AND_FIGURE


struct Point
{
    double x;
    double y;
    bool operator==(const Point &other) const noexcept { return x == other.x and y == other.y; }
    bool operator!=(const Point &other) const noexcept { return x != other.x or y != other.y; }
    friend std::ostream &operator<<(std::ostream &stream, const Point &object) {
        stream << "(" << object.x << " ; " << object.y << ")";
        return stream;
    }
};



class Figure
{
public:
    virtual ~Figure() noexcept = default;
    virtual Point findCenter() const noexcept = 0;
    virtual operator double() const noexcept = 0;
    friend std::istream &operator>>(std::istream &stream, Figure &object) { return object.read(stream); }
    friend std::ostream &operator<<(std::ostream &stream, const Figure &object) { return object.print(stream); }

protected:
    virtual std::istream &read(std::istream &) = 0;
    virtual std::ostream &print(std::ostream &) const = 0;
};

#endif