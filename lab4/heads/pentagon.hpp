#include "figure.hpp"



template <coordinate T>
class Pentagon: public Figure<T>
{
public:
    Pentagon();
    Pentagon(const Pentagon<T>&);
    Pentagon<T>&operator=(const Pentagon<T>&);
    Pentagon(Pentagon<T>&&) noexcept;
    Pentagon<T>&operator=(Pentagon<T>&&) noexcept;
    virtual ~Pentagon() noexcept ;
    bool operator==(const Pentagon<T>&) const noexcept;
    bool operator!=(const Pentagon<T>&) const noexcept;
    
    
    

protected:
    std::unique_ptr<Point<T>> top_point;
    double side;
    double a, b, c; // a = cos(72) * side ; b = sin(36) * side; c = side * sin(72)
    void abccount();
    virtual std::istream &read(std::istream &) ;
    virtual std::ostream &print(std::ostream &) const ;
};

#include "../src/pentagon.ipp"