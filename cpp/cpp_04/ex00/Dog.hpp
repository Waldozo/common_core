#pragma once
#include <iostream>
#include "Animal.hpp"
#include <string>

class Dog: public Animal
{
    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual void makeSound() const; 
        ~Dog();
};