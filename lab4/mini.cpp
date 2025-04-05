#include "heads/hexagon.hpp"
#include "heads/pentagon.hpp"
#include "heads/octagon.hpp"

int main(){
    Hexagon a;
    Hexagon b;
    std::cin >> a;
    std::cin >> b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a.findCenter() << std::endl;

    std::cout << (a != b) << std::endl;
    
    std::cout << (a != a) << std::endl;

}