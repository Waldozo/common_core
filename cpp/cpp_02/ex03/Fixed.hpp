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
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

};

// Déclaration de l'opérateur << (en dehors de la classe)
std::ostream &operator<<(std::ostream &out, const Fixed &obj);
