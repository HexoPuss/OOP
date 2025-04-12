#include "figure.hpp"

class Octagon : public Figure
{
public:
    Octagon();
    Octagon(const Octagon &);
    Octagon &operator=(const Octagon &);
    Octagon(Octagon &&) noexcept;
    Octagon &operator=(Octagon &&) noexcept;
    virtual ~Octagon() noexcept ;
    bool operator==(const Octagon &) const noexcept;
    bool operator!=(const Octagon &) const noexcept;
    virtual Point findCenter() const noexcept ;
    virtual operator double() const noexcept ;
    

protected:
    Point center;
    double side;
    double a; 
    void acount();
    virtual std::istream &read(std::istream &) ;
    virtual std::ostream &print(std::ostream &) const ;
};