#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "FragTrap";
    this->health = 100;
    this->nrj = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    this->health = 100;
    this->nrj = 100;
    this->attackDamage = 30;
}

void FragTrap::attack(const std::string &target)
{
    if (this->nrj > 0 && this->health > 0)
    {
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->nrj -= 1;
    }
    else
        std::cout << "FragTrap " << this->name << " can't attack, no energy or health left!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " High five guys!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}