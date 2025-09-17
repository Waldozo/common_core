#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) 
    : name(name), weapon(NULL) // ← Initialiser le pointeur à NULL !
{
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;  // Stocker l'adresse
}

HumanB::~HumanB() {
    // Rien à faire (on ne possède pas le Weapon)
}


void HumanB::attack(){
    if(weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " does not have any weapon" << std::endl;
}
