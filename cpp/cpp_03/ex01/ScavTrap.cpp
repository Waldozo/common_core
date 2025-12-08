#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->name = "ScavTrap";
    this->health = 100;
    this->nrj = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
    this->health = 100;
    this->nrj = 50;
    this->attackDamage = 20;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->nrj > 0 && this->health > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->nrj -= 1;
    }
    else
        std::cout << "ScavTrap " << this->name << " can't attack, no energy or health left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}