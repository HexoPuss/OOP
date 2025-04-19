#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include "../heads/point.hpp"
//#include "../heads/pentagon.hpp"


template<coordinate T>
void Pentagon<T>::abccount() {
    a = side * cos(M_PI * 72 / 180);
    b = side * sin(M_PI * 36 / 180);
    c = side * sin(M_PI * 72 / 180);
    this->center = std::make_unique<Point<T>>(top_point->x, top_point->y - (side / sin(72 * M_PI / 180) * sin(54 * M_PI / 180)));
    this->area = side * side / 4 * sqrt(25 + 10 * sqrt(5));
}


template<coordinate T>
Pentagon<T>::Pentagon(): top_point(std::make_unique<Point<T>>(0, 0)), side{5} {
    abccount();
}


template<coordinate T>
Pentagon<T>::Pentagon(const Pentagon<T> &other){
    
    if (other.top_point) {
        top_point  = std::make_unique<Point<T>>(*other.top_point);
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
Pentagon<T> &Pentagon<T>::operator=(const Pentagon<T> &other){
    if (this == &other) {
        return *this;
    }
    if (other.top_point) {
        top_point  = std::make_unique<Point<T>>(*other.top_point);
    } else {
        top_point .reset();
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
Pentagon<T>::Pentagon(Pentagon<T> &&other) noexcept{
    top_point = std::move(other.top_point);
    side = std::move(other.side);
    a = std::move(other.a);
    b = std::move(other.b);
    c = std::move(other.c);
    this->center = std::move(other.center);
    this->area = std::move(other.area);
}


template<coordinate T>
Pentagon<T> &Pentagon<T>::operator=(Pentagon<T> &&other) noexcept{
    if(&other != this){
        top_point = std::move(other.top_point);
        side = std::move(other.side);
        a = std::move(other.a);
        b = std::move(other.b);
        c = std::move(other.c);
        this->area = std::move(other.area);
        this->center = std::move(other.center);
    }
    return *this;
}
template<coordinate T>
Pentagon<T>::~Pentagon() noexcept {
    this->center.reset();
    top_point.reset();
}


template<coordinate T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) const noexcept
{
    return *top_point == *other.top_point && side == other.side;
}


template<coordinate T>
bool Pentagon<T>::operator!=(const Pentagon<T> &other) const noexcept
{
    return top_point != other.top_point || side != other.side;
}


template<coordinate T>
std::istream &Pentagon<T>::read(std::istream &stream)
{
    stream >> *top_point;
    stream >> side;
    abccount();
    return stream;
}


template<coordinate T>
std::ostream &Pentagon<T>::print(std::ostream &stream) const
{
    stream << "5-угольник: ";

    Point<T> cur = *top_point;
    stream << cur;

    cur.x -= side / 2 + a;
    cur.y -= b;
    stream << cur;

    cur.x += a;
    cur.y -= c;
    stream << cur;

    cur.x += side;
    stream << cur;

    cur.x += a;
    cur.y += c;
    stream << cur;

    return stream;
}
