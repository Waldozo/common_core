#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->BrainCat = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other){
    std::cout << "Cat copy constructor called" << std::endl;
    BrainCat = new Brain(*other.BrainCat);
}

Cat &Cat::operator=(const Cat &other){
    if(this != &other)
    {
        Animal::operator=(other);
        *BrainCat = *other.BrainCat;
    }
    return(*this);
}

void Cat::makeSound() const{
    std::cout << BLUE << "meow meow" << RESET << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
    delete BrainCat;
}