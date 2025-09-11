#pragma once
#include <string>
#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <cctype>

class PhoneBook
{
private:
    Contact contact[8];
    int contact_count;
    int current_index;

public:
    PhoneBook();  // Constructeur
    ~PhoneBook(); // Destructeur
    void addContact();
    void displayAllContact();
    void searchContact();
    void exitContact();
};