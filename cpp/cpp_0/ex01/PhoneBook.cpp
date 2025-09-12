#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contact_count = 0;
    this->current_index = 0;
}

void PhoneBook::addContact()
{
    contact[current_index].setContact();
    current_index = (current_index + 1) % 8;
    if (contact_count < 8)
        contact_count++;
}

std::string formatField(const std::string &field)
{
    if (field.length() > 10)
    {
        return field.substr(0, 9) + ".";
    }
    return field;
}

void PhoneBook::displayAllContact()
{
    std::cout << "          ====== Phone Book ======" << std::endl;
    std::cout << "Index     | First_name|  Last_name|   Nickanme|" <<std::endl;
    for (int i = 0; i < contact_count; i++)
    {
        std::cout << std::setw(10) << (i + 1) << "| "
                  << std::setw(10) << formatField(contact[i].getFirstName()) << "| "
                  << std::setw(10) << formatField(contact[i].getLastName()) << "| "
                  << std::setw(10) << formatField(contact[i].getNicknameName()) << "|" << std::endl;
    }

    std::cout << "===============" << std::endl;
}

void PhoneBook::searchContact()
{
    if (contact_count == 0)
    {
        std::cout << "No contacts available" << std::endl;
        return;
    }

    displayAllContact();

    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid index format" << std::endl;
        return;
    }

    int index = input[0] - '0';

    if (index < 1 || index > contact_count)
    {
        std::cout << "Index out of range" << std::endl;
        return;
    }

    contact[index - 1].displayContact();
}

PhoneBook::~PhoneBook()
{
    return;
}