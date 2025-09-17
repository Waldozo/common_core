#pragma once
#include <string>
#include <iostream>
#include <cctype>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    Weapon(const std::string& type);
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string& newType);
};