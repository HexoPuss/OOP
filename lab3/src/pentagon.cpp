#include "../heads/pentagon.hpp"

void Pentagon::abccount() {
    a = side * cos(M_PI * 72 / 180);
    b = side * sin(M_PI * 36 / 180);
    c = side * sin(M_PI * 72 / 180);
}

Pentagon::Pentagon(): top_point{0, 0}, side{5} {
    abccount();
}

Pentagon::Pentagon(const Pentagon &other){
    top_point = other.top_point;
    side = other.side;
    a = other.a;
    b = other.b;
}

Pentagon &Pentagon::operator=(const Pentagon &other){
    if(&other != this){
        top_point = other.top_point;
        side = other.side;
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

Pentagon::Pentagon(Pentagon &&other) noexcept{
    top_point = std::move(other.top_point);
    side = std::move(other.side);
    a = std::move(other.a);
    b = std::move(other.b);
    c = std::move(other.c);
}

Pentagon &Pentagon::operator=(Pentagon &&other) noexcept{
    if(&other != this){
        top_point = std::move(other.top_point);
        side = std::move(other.side);
        a = std::move(other.a);
        b = std::move(other.b);
        c = std::move(other.c);
    }
    return *this;
}

Pentagon::~Pentagon() noexcept {}

bool Pentagon::operator==(const Pentagon &other) const noexcept
{
    return top_point == other.top_point && side == other.side;
}

bool Pentagon::operator!=(const Pentagon &other) const noexcept
{
    return top_point != other.top_point || side != other.side;
}

Point Pentagon::findCenter() const noexcept{
    Point center;
    center.y = top_point.y - (side / sin(72 * M_PI / 180) * sin(54 * M_PI / 180));
    center.x = top_point.x;
    return center;
}

Pentagon::operator double() const noexcept{
    return side * side / 4 * sqrt(25 + 10 * sqrt(5));
}

std::istream &Pentagon::read(std::istream &stream)
{
    stream >> top_point.x;
    stream >> top_point.y;
    stream >> side;
    abccount();
    return stream;
}

std::ostream &Pentagon::print(std::ostream &stream) const
{
    stream << "5-угольник: ";

    Point cur = top_point;
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

