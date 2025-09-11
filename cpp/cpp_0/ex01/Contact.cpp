#include "Contact.hpp"

bool isValidContact(const std::string &contact)
{
    return contact.length() > 0;
}

void Contact::setContact()
{
    do{
        std::cout << "Enter your first name : ";
        std::getline(std::cin, first_name);
        if(!isValidContact(first_name)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(first_name));

    do{
    std::cout << "Enter your last name : ";
    std::getline(std::cin, last_name);
           if(!isValidContact(last_name)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(last_name));

    do{
    std::cout << "Enter your nickname : ";
    std::getline(std::cin, nickname);
           if(!isValidContact(nickname)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(nickname));

    do{
    std::cout << "Enter your phone_number : ";
    std::getline(std::cin, phone_number);
           if(!isValidContact(phone_number)){
            std::cout <<"This field can't be empty" <<std::endl; 
        }
    }while(!isValidContact(phone_number));

    do{
    std::cout << "Enter your darkest_secret : ";
    std::getline(std::cin, darkest_secret);
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