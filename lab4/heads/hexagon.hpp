#include "figure.hpp"


template<coordinate T>
class Hexagon: public Figure<T>
{
public:
    Hexagon();
    Hexagon(const Hexagon<T>&);
    Hexagon<T>&operator=(const Hexagon<T>&);
    Hexagon(Hexagon<T>&&) noexcept;
    Hexagon<T>&operator=(Hexagon<T>&&) noexcept;
    virtual ~Hexagon() noexcept ;
    bool operator==(const Hexagon<T>&) const noexcept;
    bool operator!=(const Hexagon<T>&) const noexcept;
    
    

protected:
    std::unique_ptr<Point<T>> left_point;
    double side;
    double a, b; // a = cos(60) * side ; b = sin(60) * side
    void abcount();
    virtual std::istream &read(std::istream &) ;
    virtual std::ostream &print(std::ostream &) const ;
};

#include "../src/hexagon.ipp"