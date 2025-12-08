#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("John", 50); // ← Utilise votre nouveau constructeur
    std::cout << b1.getName() << ", has grade " << b1.getGrade() << std::endl;
    try
    {
        std::cout << b1 << std::endl;
     
        Bureaucrat b2("Alice", 150); // Grade minimum

        b2.DecrementGrade(); // Décrémenter le grade d'Alice
        std::cout << b2.getName() << " has grade " << b2.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
     try
    {
        Bureaucrat b3("Bob", 1); // Grade maximum
        b3.IncrementGrade(); // Incrémenter le grade de Bob
        std::cout << b3.getName() << ", has grade " << b3.getGrade() << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}