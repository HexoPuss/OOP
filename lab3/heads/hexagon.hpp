#include "figure.hpp"

class Hexagon : public Figure
{
public:
    Hexagon();
    Hexagon(const Hexagon &);
    Hexagon &operator=(const Hexagon &);
    Hexagon(Hexagon &&) noexcept;
    Hexagon &operator=(Hexagon &&) noexcept;
    virtual ~Hexagon() noexcept override;
    bool operator==(const Hexagon &) const noexcept;
    bool operator!=(const Hexagon &) const noexcept;
    virtual Point findCenter() const noexcept override;
    virtual operator double() const noexcept override;
    

protected:
    Point left_point;
    double side;
    double a, b; // a = sin(60) * side ; b = cos(60) * side
    void abcount();
    virtual std::istream &read(std::istream &) override;
    virtual std::ostream &print(std::ostream &) const override;
};