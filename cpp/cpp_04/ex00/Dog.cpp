#include "Dog.hpp"

Dog::Dog(): Animal(){
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";    
}

Dog::Dog(const Dog &other) : Animal(other){
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
    if(this != &other)
    {
        Animal::operator=(other);
    }
    return(*this);
}

void Dog::makeSound() const{
    std::cout << BLUE << "waf waf" << RESET << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}