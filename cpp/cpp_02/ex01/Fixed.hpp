#pragma once
#include <iostream>
#include <cmath>

#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Fixed
{
private:
    int value;
    static const int fractionalBits;

public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed(const int n);
    Fixed(const float f);
    Fixed &operator=(const Fixed &obj);
    ~Fixed();
    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);
