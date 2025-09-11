#pragma once
#include <string>
#include <iostream>
#include <cctype>
class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void setContact();
    void displayContact() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNicknameName() const;
};