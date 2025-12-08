#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    std::cout << "=== TEST CONSTRUCTEURS ===" << std::endl;
    Fixed a;                    // Constructeur par défaut
    Fixed b(42);               // Constructeur int
    Fixed c(42.42f);           // Constructeur float
    Fixed d(b);                // Constructeur de copie
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl; 
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    
    std::cout << "\n=== TEST OPÉRATEURS DE COMPARAISON ===" << std::endl;
    std::cout << "b > c : " << (b > c) << std::endl;
    std::cout << "b < c : " << (b < c) << std::endl;
    std::cout << "b >= c : " << (b >= c) << std::endl;
    std::cout << "b <= c : " << (b <= c) << std::endl;
    std::cout << "b == c : " << (b == c) << std::endl;
    std::cout << "b != c : " << (b != c) << std::endl;
    
    std::cout << "\n=== TEST OPÉRATEURS ARITHMÉTIQUES ===" << std::endl;
    Fixed x(10.5f);
    Fixed y(2.5f);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;
    
    std::cout << "\n=== TEST INCRÉMENTATION/DÉCRÉMENTATION ===" << std::endl;
    Fixed z(5.0f);
    std::cout << "z initial = " << z << std::endl;
    std::cout << "++z = " << (++z) << std::endl;
    std::cout << "z après ++z = " << z << std::endl;
    std::cout << "z++ = " << (z++) << std::endl;
    std::cout << "z après z++ = " << z << std::endl;
    std::cout << "--z = " << (--z) << std::endl;
    std::cout << "z-- = " << (z--) << std::endl;
    std::cout << "z final = " << z << std::endl;
    
    std::cout << "\n=== TEST FONCTIONS MIN/MAX ===" << std::endl;
    Fixed m1(3.5f);
    Fixed m2(7.2f);
    std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
    std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;
    
    std::cout << "\n=== TEST toInt() ===" << std::endl;
    std::cout << "c.toInt() = " << c.toInt() << std::endl;
    std::cout << "x.toInt() = " << x.toInt() << std::endl;
    
    return 0;
}