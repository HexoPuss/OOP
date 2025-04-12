#include "../heads/hexagon.hpp"

void Hexagon::abcount() {
    a = side * cos(M_PI / 3);
    b = side * sin(M_PI / 3);
}

Hexagon::Hexagon(): left_point{0, 0}, side{5} {
    abcount();
}

Hexagon::Hexagon(const Hexagon &other){
    left_point = other.left_point;
    side = other.side;
    a = other.a;
    b = other.b;
}

Hexagon &Hexagon::operator=(const Hexagon &other){
    if(&other != this){
        left_point = other.left_point;
        side = other.side;
        a = other.a;
        b = other.b;
    }
    return *this;
}

Hexagon::Hexagon(Hexagon &&other) noexcept{
    left_point = std::move(other.left_point);
    side = std::move(other.side);
    a = std::move(other.a);
    b = std::move(other.b);
}

Hexagon &Hexagon::operator=(Hexagon &&other) noexcept{
    if(&other != this){
        left_point = std::move(other.left_point);
        side = std::move(other.side);
        a = std::move(other.a);
        b = std::move(other.b);
    }
    return *this;
}

Hexagon::~Hexagon() noexcept {}

bool Hexagon::operator==(const Hexagon &other) const noexcept
{
    return (left_point == other.left_point) and (side == other.side);
}

bool Hexagon::operator!=(const Hexagon &other) const noexcept
{
    return (left_point != other.left_point) or (side != other.side);
}

Point Hexagon::findCenter() const noexcept{
    Point center;
    center.y = left_point.y;
    center.x = left_point.x + a + (side / 2);
    return center;
}

Hexagon::operator double() const noexcept{
    return side * side * 3 / 2 * sqrt(3);
}

std::istream &Hexagon::read(std::istream &stream)
{
    stream >> left_point.x;
    stream >> left_point.y;
    stream >> side;
    abcount();
    return stream;
}

std::ostream &Hexagon::print(std::ostream &stream) const
{
    stream << "6-угольник: ";

    Point cur = left_point;
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

