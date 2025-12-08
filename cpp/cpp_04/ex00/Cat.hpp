#pragma once
#include <iostream>
#include "Animal.hpp"
#include <string>

class Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual void makeSound() const;
        ~Cat();
};