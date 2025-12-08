#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    this->name = "ClapTrap";
    this->health = 100;
    this->attackDamage = 50;
    this->nrj = 20;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Name constructor called" << std::endl;
    this->name = name;
    this->health = 100;
    this->attackDamage = 50;
    this->nrj = 20;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->nrj > 0 && this->health > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->nrj -= 1;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't attack, no energy or health left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->health -= amount;
    if (this->health < 0)
        this->health = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->nrj > 0 && this->health > 0)
    {
        std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
        this->health += amount;
        this->nrj -= 1;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't repair, no energy or health left!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}