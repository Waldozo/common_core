#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string command;

    PhoneBook iPhone;
    bool running = true;

    while (running)
    {
        std::cout << "enter : ADD or SEARCH or EXIT\n";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            iPhone.addContact();
        }
        else if (command == "SEARCH")
        {
            iPhone.searchContact();
        }
        else if (command == "EXIT")
        {
            running = false;
        }
    }
    return (0);
}