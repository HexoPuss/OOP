#include "figure.hpp"

class Octagon : public Figure
{
public:
    Octagon();
    Octagon(const Octagon &);
    Octagon &operator=(const Octagon &);
    Octagon(Octagon &&) noexcept;
    Octagon &operator=(Octagon &&) noexcept;
    virtual ~Octagon() noexcept override;
    bool operator==(const Octagon &) const noexcept;
    bool operator!=(const Octagon &) const noexcept;
    virtual Point findCenter() const noexcept override;
    virtual operator double() const noexcept override;
    

protected:
    Point center;
    double side;
    double a; // a = sin(60) * side ; b = cos(60) * side
    void acount();
    virtual std::istream &read(std::istream &) override;
    virtual std::ostream &print(std::ostream &) const override;
};