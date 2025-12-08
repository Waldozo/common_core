#include "Fixed.hpp"
#include <climits>

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    if (n > (INT_MAX >> fractionalBits))
    {
        std::cout << BLUE << "Overflow: value " << n << " is too large, setting to 0" << RESET << std::endl;
        this->value = 0;
    }
    else if (n < (INT_MIN >> fractionalBits))
    {
        std::cout << RED << "Underflow: value " << n << " is too small, setting to 0" << RESET << std::endl;
        this->value = 0;
    }
    else
    {
        this->value = n << fractionalBits;
    }
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    float scaled = f * (1 << fractionalBits);

    if (scaled > (float)INT_MAX)
    {
        std::cout << RED << "Float overflow: " << f << " is too large" << RESET << std::endl;
        this->value = 0;
    }
    else if (scaled < (float)INT_MIN)
    {
        std::cout << RED << "Float underflow: " << f << " is too small" << RESET << std::endl;
        this->value = 0;
    }
    else
    {
        this->value = roundf(scaled);
    }
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = obj.value;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &obj)
        return (*this);
    this->value = obj.value;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}

int Fixed::toInt() const
{
    return (value >> fractionalBits);
}

float Fixed::toFloat() const
{
    return ((float)value / (1 << fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}