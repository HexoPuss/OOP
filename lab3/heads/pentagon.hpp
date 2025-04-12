#include "figure.hpp"

class Pentagon : public Figure
{
public:
    Pentagon();
    Pentagon(const Pentagon &);
    Pentagon &operator=(const Pentagon &);
    Pentagon(Pentagon &&) noexcept;
    Pentagon &operator=(Pentagon &&) noexcept;
    virtual ~Pentagon() noexcept ;
    bool operator==(const Pentagon &) const noexcept;
    bool operator!=(const Pentagon &) const noexcept;
    virtual Point findCenter() const noexcept ;
    virtual operator double() const noexcept ;
    

protected:
    Point top_point;
    double side;
    double a, b, c; // a = cos(72) * side ; b = sin(36) * side; c = side * sin(72)
    void abccount();
    virtual std::istream &read(std::istream &) ;
    virtual std::ostream &print(std::ostream &) const ;
};