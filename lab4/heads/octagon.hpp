#include "figure.hpp"


template <coordinate T>
class Octagon: public Figure<T>
{
public:
    Octagon();
    Octagon(const Octagon<T>&);
    Octagon<T>&operator=(const Octagon<T>&);
    Octagon(Octagon<T>&&) noexcept;
    Octagon<T>&operator=(Octagon<T>&&) noexcept;
    virtual ~Octagon() noexcept ;
    bool operator==(const Octagon<T>&) const noexcept;
    bool operator!=(const Octagon<T>&) const noexcept;
    
    
    

protected:
    //center уже есть!!!
    double side;
    double a; // a = side * sqrt(2)
    void acount();
    virtual std::istream &read(std::istream &) ;
    virtual std::ostream &print(std::ostream &) const ;
};

#include "../src/octagon.ipp"