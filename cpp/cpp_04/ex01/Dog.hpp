#pragma once
#include <iostream>
#include "Animal.hpp"
#include <string>
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain* BrainDog;
    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual void makeSound() const; 
        ~Dog();
};