#include "../heads/octagon.hpp"

void Octagon::acount() {
    a = side / sqrt(2);
}

Octagon::Octagon(): center{0, 0}, side{5} {
    acount();
}

Octagon::Octagon(const Octagon &other){
    center = other.center;
    side = other.side;
    a = other.a;
}

Octagon &Octagon::operator=(const Octagon &other){
    if(&other != this){
        center = other.center;
        side = other.side;
        a = other.a;
        
    }
    return *this;
}

Octagon::Octagon(Octagon &&other) noexcept{
    center = std::move(other.center);
    side = std::move(other.side);
    a = std::move(other.a);
    
}

Octagon &Octagon::operator=(Octagon &&other) noexcept{
    if(&other != this){
        center = std::move(other.center);
        side = std::move(other.side);
        a = std::move(other.a);
        
    }
    return *this;
}

Octagon::~Octagon() noexcept {}

bool Octagon::operator==(const Octagon &other) const noexcept
{
    return center == other.center && side == other.side;
}

bool Octagon::operator!=(const Octagon &other) const noexcept
{
    return center != other.center || side != other.side;
}

Point Octagon::findCenter() const noexcept{
    return center;
}

Octagon::operator double() const noexcept{
    return 2 * side * side * (1 + sqrt(2));
}

std::istream &Octagon::read(std::istream &stream)
{
    stream >> center.x;
    stream >> center.y;
    stream >> side;
    acount();
    return stream;
}

std::ostream &Octagon::print(std::ostream &stream) const
{
    stream << "6-угольник: ";

    Point cur = center;
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

