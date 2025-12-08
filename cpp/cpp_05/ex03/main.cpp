#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "=== TEST 1: Creation de Bureaucrat ===" << std::endl;

    Bureaucrat alice("Alice", 1); // Grade très élevé pour tout signer et exécuter

    std::cout << alice << std::endl;

    std::cout << "\n=== TEST 2: Creation d'un Intern ===" << std::endl;

    Intern someRandomIntern;
    std::cout << "Intern created successfully" << std::endl;

    std::cout << "\n=== TEST 3: Intern makeForm() - Forms valides ===" << std::endl;

    // Test de l'exemple exact du sujet
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf;
    }

    std::cout << std::endl;

    // Test Shrubbery Creation Form
    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (scf)
    {
        std::cout << *scf << std::endl;
        alice.signForm(*scf);
        alice.executeForm(*scf);
        delete scf;
    }

    std::cout << std::endl;

    // Test Presidential Pardon Form
    AForm *ppf = someRandomIntern.makeForm("presidential pardon", "criminal");
    if (ppf)
    {
        std::cout << *ppf << std::endl;
        alice.signForm(*ppf);
        alice.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n=== TEST 4: Intern makeForm() - Form invalide ===" << std::endl;

    // Test avec un nom de form inexistant
    AForm *invalidForm = someRandomIntern.makeForm("invalid form", "target");
    if (invalidForm)
    {
        std::cout << "ERROR: Should not have created form!" << std::endl;
        delete invalidForm;
    }
    else
    {
        std::cout << "Correctly returned NULL for invalid form name" << std::endl;
    }

    // Test avec des variations de noms
    std::cout << std::endl;
    AForm *wrongCase = someRandomIntern.makeForm("Robotomy Request", "target");
    if (!wrongCase)
    {
        std::cout << "Correctly case-sensitive: 'Robotomy Request' not found" << std::endl;
    }

    std::cout << "\n=== TEST 5: Test de copie d'Intern ===" << std::endl;

    Intern intern2 = someRandomIntern; // Test constructeur de copie
    Intern intern3;
    intern3 = someRandomIntern; // Test opérateur d'assignation

    AForm *testForm = intern2.makeForm("robotomy request", "test_target");
    if (testForm)
    {
        std::cout << "Copied intern works correctly" << std::endl;
        delete testForm;
    }

    return 0;
}