#include "contact.hpp"

void Contact::setContact()
{
    std::cout << "Enter your first name";
    std::getline (std::cin, first_name);
    std::cout << "Enter your last name";
    std::getline (std::cin, last_name);
    std::cout << "Enter your nickname";
    std::getline (std::cin, nickname);
    std::cout << "Enter your phone_number";
    std::getline (std::cin, phone_number);
    std::cout << "Enter your darkest_secret";
    std::getline (std::cin, darkest_secret);
}
