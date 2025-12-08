#pragma once
#include <iostream>
#include <string>
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

class WrongAnimal {

    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};