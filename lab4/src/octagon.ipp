#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include "../heads/point.hpp"
//#include "../heads/octagon.hpp"

template<coordinate T>
void Octagon<T>::acount() {
    a = side / sqrt(2);
    this->area = 2 * side * side * (1 + sqrt(2));
}

template<coordinate T>
Octagon<T>::Octagon(): side{0} {
    this->center = std::make_unique<Point<T>>(0, 0);
    acount();
}

template<coordinate T>
Octagon<T>::Octagon(const Octagon<T> &other){
    // Глубокая копия
    side = other.side;
    a = other.a;
    if (other.center) {
        this->center = std::make_unique<Point<T>>(*other.center);
    }
    this->area = other.area;
}

template<coordinate T>
Octagon<T> &Octagon<T>::operator=(const Octagon<T> &other){
    if (this == &other) {
        return *this;
    }
    side = other.side;
    a = other.a;
    if (other.center) {
        this->center = std::make_unique<Point<T>>(*other.center);
    } else {
        this->center.reset();
    }
    this->area = other.area;
    return *this;
}

template<coordinate T>
Octagon<T>::Octagon(Octagon<T> &&other) noexcept{
    this->center = std::move(other.center);
    side = std::move(other.side);
    a = std::move(other.a);
    this->area = std::move(other.area);
    
}


template<coordinate T>
Octagon<T> &Octagon<T>::operator=(Octagon<T> &&other) noexcept{
    if (this == &other) {
        return *this;
    }
    
    side = std::move(other.side);
    a = std::move(other.a);
    
    this->center = std::move(other.center);
    this->area = other.area;
    other.area = 0;
    return *this;
    
}


template<coordinate T>
Octagon<T>::~Octagon() noexcept {
    this->center.reset();
}


template<coordinate T>
bool Octagon<T>::operator==(const Octagon<T> &other) const noexcept
{
    return (*this->center == *other.center) && side == other.side;
}


template<coordinate T>
bool Octagon<T>::operator!=(const Octagon<T> &other) const noexcept
{
    return *this->center != *other.center || side != other.side;
}






template<coordinate T>
std::istream &Octagon<T>::read(std::istream &stream)
{
    stream >> *this->center;
    stream >> side;
    acount();
    return stream;
}


template<coordinate T>
std::ostream &Octagon<T>::print(std::ostream &stream) const
{
    stream << "8-угольник: ";

    Point<T> cur = *(this->center);
    cur.x -= side / 2;
    cur.y += side / 2 + a;
    stream << cur;

    cur.x -= a;
    cur.y -= a;
    stream << cur;

    cur.y -= side;
    stream << cur;

    cur.x += a;
    cur.y -= a;
    stream << cur;

    cur.x += side;
    stream << cur;

    cur.x += a;
    cur.y += a;
    stream << cur;

    cur.y += side;
    stream << cur;

    cur.x -= a;
    cur.y += a;
    stream << cur;

    return stream;
}

