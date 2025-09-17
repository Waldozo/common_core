#include "Weapon.hpp"

Weapon::Weapon() {
    this->type = "";  // ou une valeur par défaut
}

Weapon::Weapon(const std::string& type) {
    this->type = type;
}

Weapon::~Weapon() {
    // Rien à faire pour cette classe simple
}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const std::string& newType) {
    this->type = newType;
}