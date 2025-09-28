#include "Contact.hpp"

bool isValidContact(const std::string &contact)
{
    return contact.length() > 0;
}

std::string cleanInput(const std::string &input)
{
    std::string cleaned;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '\033' && i + 2 < input.length() && input[i + 1] == '[')
        {
            i += 2;
            while (i < input.length() && (input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z'))
                i++;
            continue;
        }
        
        if (input[i] >= 32 && input[i] <= 126)
        {
            cleaned += input[i];
        }
    }
    return cleaned;
}

void Contact::setContact()
{
    do{
        std::cout << "Enter your first name : ";
        if (!std::getline(std::cin, first_name))
        {
            std::cout << "\nEOF detected. Contact creation cancelled.\n";
            return;
        }
        first_name = cleanInput(first_name);
        if(!isValidContact(first_name)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(first_name));

    do{
    std::cout << "Enter your last name : ";
    if (!std::getline(std::cin, last_name))
    {
        std::cout << "\nEOF detected. Contact creation cancelled.\n";
        return;
    }
    last_name = cleanInput(last_name);
           if(!isValidContact(last_name)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(last_name));

    do{
    std::cout << "Enter your nickname : ";
    if (!std::getline(std::cin, nickname))
    {
        std::cout << "\nEOF detected. Contact creation cancelled.\n";
        return;
    }
    nickname = cleanInput(nickname);
           if(!isValidContact(nickname)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(nickname));

    do{
    std::cout << "Enter your phone_number : ";
    if (!std::getline(std::cin, phone_number))
    {
        std::cout << "\nEOF detected. Contact creation cancelled.\n";
        return;
    }
    phone_number = cleanInput(phone_number);
           if(!isValidContact(phone_number)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(phone_number));

    do{
    std::cout << "Enter your darkest_secret : ";
    if (!std::getline(std::cin, darkest_secret))
    {
        std::cout << "\nEOF detected. Contact creation cancelled.\n";
        return;
    }
    darkest_secret = cleanInput(darkest_secret);
           if(!isValidContact(darkest_secret)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(darkest_secret));
}

void Contact::displayContact() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNicknameName() const { return nickname; }