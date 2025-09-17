#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();
    void attack();
};