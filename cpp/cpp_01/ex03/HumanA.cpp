#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon& weapon) 
    : name(name), weapon(weapon) // initialisation de la liste
{
}

HumanA::~HumanA() {
  // pas de memoire dynamique
}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

