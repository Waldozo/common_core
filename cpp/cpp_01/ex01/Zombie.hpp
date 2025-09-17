#pragma once
#include <string>
#include <iostream>
#include <cctype>
class Zombie
{
private:
    std::string ZombieName;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie* zombieHorde( int N, std::string name );