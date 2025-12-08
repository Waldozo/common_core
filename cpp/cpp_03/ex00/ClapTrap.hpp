#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string name;
    int health;
    int nrj;
    int attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};