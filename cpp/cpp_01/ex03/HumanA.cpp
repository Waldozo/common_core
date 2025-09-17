#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon& weapon) 
    : name(name), weapon(weapon) // ← Liste d'initialisation obligatoire !
{
}

HumanA::~HumanA() {
    // Rien à faire (pas de mémoire dynamique)
}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

