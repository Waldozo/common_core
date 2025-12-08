#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: Creation de Bureaucrats ===" << std::endl;

    Bureaucrat alice("Alice", 10);      // Grade élevé (peut signer beaucoup)
    Bureaucrat bob("Bob", 50);          // Grade moyen
    Bureaucrat charlie("Charlie", 100); // Grade bas

    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << charlie << std::endl;

    std::cout << "\n=== TEST 2: Creation de Forms ===" << std::endl;

    Form taxForm("Tax Form", 20);      // Facile à signer
    Form secretForm("Secret Form", 5); // Difficile à signer
    Form easyForm("Easy Form", 80);    // Très facile à signer

    std::cout << taxForm << std::endl;
    std::cout << secretForm << std::endl;
    std::cout << easyForm << std::endl;

    std::cout << "\n=== TEST 3: Signature réussie ===" << std::endl;

    try
    {
        alice.signForm(taxForm);  // Alice (grade 10) peut signer taxForm (grade 20)
        alice.signForm(easyForm); // Alice (grade 10) peut signer easyForm (grade 80)
        bob.signForm(easyForm);   // Bob (grade 50) peut signer easyForm (grade 80)
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Signature échoue (grade trop bas) ===" << std::endl;

    try
    {
        charlie.signForm(taxForm); // Charlie (grade 100) ne peut pas signer taxForm (grade 20)
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        bob.signForm(secretForm); // Bob (grade 50) ne peut pas signer secretForm (grade 5)
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Tentative de re-signature ===" << std::endl;

    try
    {
        alice.signForm(taxForm);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: État final des forms ===" << std::endl;

    std::cout << taxForm << std::endl;
    std::cout << secretForm << std::endl;
    std::cout << easyForm << std::endl;

    std::cout << "\n=== TEST 7: Form avec grade invalide ===" << std::endl;

    try
    {
        Form invalidForm("Invalid", 0); // Grade trop élevé
    }
    catch (std::exception &e)
    {
        std::cout << "Exception création form grade 0: " << e.what() << std::endl;
    }

    try
    {
        Form invalidForm2("Invalid2", 151); // Grade trop bas
    }
    catch (std::exception &e)
    {
        std::cout << "Exception création form grade 151: " << e.what() << std::endl;
    }

    return 0;
}