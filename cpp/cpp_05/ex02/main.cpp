#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== TEST 1: Creation de Bureaucrats ===" << std::endl;

    Bureaucrat alice("Alice", 1);       // Grade très élevé
    Bureaucrat bob("Bob", 50);          // Grade moyen
    Bureaucrat charlie("Charlie", 150); // Grade bas

    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << charlie << std::endl;

    std::cout << "\n=== TEST 2: Creation des Forms concrètes ===" << std::endl;

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("target");
    PresidentialPardonForm pardon("criminal");

    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n=== TEST 3: Signature des forms ===" << std::endl;

    alice.signForm(shrubbery); // Alice peut signer (grade 1 vs 145)
    alice.signForm(robotomy);  // Alice peut signer (grade 1 vs 72)
    alice.signForm(pardon);    // Alice peut signer (grade 1 vs 25)

    std::cout << "\n=== TEST 4: Exécution des forms ===" << std::endl;

    alice.executeForm(shrubbery); // Alice peut exécuter (grade 1 vs 137)
    alice.executeForm(robotomy);  // Alice peut exécuter (grade 1 vs 45)
    alice.executeForm(pardon);    // Alice peut exécuter (grade 1 vs 5)

    std::cout << "\n=== TEST 5: Échecs d'exécution (grade trop bas) ===" << std::endl;

    charlie.executeForm(shrubbery); // Charlie ne peut pas (grade 150 vs 137)

    return 0;
}