#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal contructor called" << std::endl;
    this->type = "Unknown";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = other.type;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << BLUE << "Generic animal sound" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other){
    if(this != &other)
    {
        this->type = other.type;
    }
    return(*this);
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}