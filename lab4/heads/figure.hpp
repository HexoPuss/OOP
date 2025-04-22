#include <iostream>
#include <stdexcept>
#include <cmath>
#include "point.hpp"
#define EPS 0.001
#ifndef FIGURE
#define FIGURE

template <coordinate T>
class Figure
{
public:
    virtual ~Figure() noexcept = default;
    friend std::istream &operator>>(std::istream &stream, Figure &object) { return object.read(stream); }
    friend std::ostream &operator<<(std::ostream &stream, const Figure &object) { return object.print(stream); }

    std::unique_ptr<Point<T>> findCenter() const noexcept{return std::make_unique<Point<T>> (*center);}

    operator double() const noexcept{ return area; }

protected:
    std::unique_ptr<Point<T>> center;
    double area;
    virtual std::istream &read(std::istream &) = 0;
    virtual std::ostream &print(std::ostream &) const = 0;
};

#endif