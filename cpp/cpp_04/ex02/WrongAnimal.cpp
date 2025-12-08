#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal contructor called" << std::endl;
    this->type = "Unknown";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << RED << "Generic WrongAnimal sound" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    if(this != &other)
    {
        this->type = other.type;
    }
    return(*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}