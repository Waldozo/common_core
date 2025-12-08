#include "Zombie.hpp"

Zombie::Zombie()
{
    this->ZombieName = "Unknown";
}

void Zombie::announce()
{
    std::cout << ZombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    ZombieName = name;
}

Zombie::~Zombie()
{
    std::cout << ZombieName << " has been destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    ZombieName = name;
}