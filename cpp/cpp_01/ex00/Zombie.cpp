#include "Zombie.hpp"

Zombie::Zombie(){
    this->ZombieName = "Unknown";
}

void Zombie::announce(){
    std::cout << ZombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name){
    ZombieName = name;
}

Zombie::~Zombie(){
     std::cout << "Destructor has been called" << std::endl;
}