#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base *ptr;

    std::cout << "Test 1: Generating and identifying by pointer" << std::endl;
    ptr = generate();
    std::cout << "Identify by pointer: ";
    identify(ptr);
    std::cout << "Identify by reference: ";
    identify(*ptr);
    delete ptr;

    std::cout << "\nTest 2: Multiple generations" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        ptr = generate();
        std::cout << "Object " << i + 1 << " - Pointer: ";
        identify(ptr);
        std::cout << "Object " << i + 1 << " - Reference: ";
        identify(*ptr);
        delete ptr;
    }

    std::cout << "\nTest 3: Direct class instantiation" << std::endl;
    A a;
    B b;
    C c;
    
    std::cout << "A class - Pointer: ";
    identify(&a);
    std::cout << "A class - Reference: ";
    identify(a);
    
    std::cout << "B class - Pointer: ";
    identify(&b);
    std::cout << "B class - Reference: ";
    identify(b);
    
    std::cout << "C class - Pointer: ";
    identify(&c);
    std::cout << "C class - Reference: ";
    identify(c);

    return 0;
}
