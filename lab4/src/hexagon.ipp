#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include "../heads/point.hpp"
//#include "../heads/hexagon.hpp"

template<coordinate T>
void Hexagon<T>::abcount() {
    a = side * cos(M_PI / 3);
    b = side * sin(M_PI / 3);
    this->center = std::make_unique<Point<T>>(left_point->X() + side, left_point->Y());
    this->area = side * side * 3 / 2 * sqrt(3);
}
template<coordinate T>
Hexagon<T>::Hexagon():  left_point(std::make_unique<Point<T>>(0, 0)), side{5} {
    abcount();
}

template<coordinate T>
Hexagon<T>::Hexagon(const Hexagon<T>& other)
{
    // Глубокая копия
    if (other.left_point) {
        left_point = std::make_unique<Point<T>>(*other.left_point);
    }
    side = other.side;
    a = other.a;
    b = other.b;
    if (other.center) {
        this->center = std::make_unique<Point<T>>(*other.center);
    }
    this->area = other.area;
}

template<coordinate T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& other)
{
    if (this == &other) {
        return *this;
    }
    if (other.left_point) {
        left_point = std::make_unique<Point<T>>(*other.left_point);
    } else {
        left_point.reset();
    }
    side = other.side;
    a = other.a;
    b = other.b;
    if (other.center) {
        this->center = std::make_unique<Point<T>>(*other.center);
    } else {
        this->center.reset();
    }
    this->area = other.area;
    return *this;
}


template<coordinate T>
Hexagon<T>::Hexagon(Hexagon<T> &&other) noexcept{
    left_point = std::move(other.left_point);
    side = std::move(other.side);
    a = std::move(other.a);
    b = std::move(other.b);
    this->center = std::move(other.center);
    this->area = std::move(other.area);
}


template <coordinate T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other) noexcept
{
    if (this == &other) {
        return *this;
    }
    left_point = std::move(other.left_point);
    side = std::move(other.side);
    a = std::move(other.a);
    b = std::move(other.b);
    this->center = std::move(other.center);
    this->area = other.area;
    other.area = 0;
    return *this;
}

template<coordinate T>
Hexagon<T>::~Hexagon() noexcept {
    left_point.reset();
    this->center.reset();
}


template<coordinate T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) const noexcept
{
    return (left_point == other.left_point) and (side == other.side);
}


template<coordinate T>
bool Hexagon<T>::operator!=(const Hexagon<T> &other) const noexcept
{
    return (left_point != other.left_point) or (side != other.side);
}



template<coordinate T>
std::istream &Hexagon<T>::read(std::istream &stream)
{
    
    stream >> *left_point;
    stream >> side;
    abcount();
    return stream;
}



template<coordinate T>
std::ostream &Hexagon<T>::print(std::ostream &stream) const
{
    stream << "6-угольник: ";

    Point<T> cur = *left_point;
    stream << cur;

    cur.x += a;
    cur.y += b;
    stream << cur;

    cur.x += side;
    stream << cur;

    cur.x += a;
    cur.y -= b;
    stream << cur;

    cur.x -= a;
    cur.y -= b;
    stream << cur;

    cur.x -= side;
    stream << cur;

    return stream;
}