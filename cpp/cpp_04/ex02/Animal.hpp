#pragma once
#include <iostream>
#include <string>
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
};