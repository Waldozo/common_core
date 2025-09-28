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
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nEOF detected. Exiting...\n";
            break;
        }
        // Clean the command input (remove escape sequences)
        std::string cleanCommand;
        for (size_t i = 0; i < command.length(); i++)
        {
            if (command[i] >= 32 && command[i] <= 126)
                cleanCommand += command[i];
        }
        command = cleanCommand;
        
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