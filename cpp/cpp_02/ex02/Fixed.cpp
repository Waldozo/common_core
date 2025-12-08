#include "Fixed.hpp"
#include <climits>
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
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
    this->value = obj.value;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
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

bool Fixed::operator>(const Fixed &other) const
{
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    if ((other.value > 0 && this->value > INT_MAX - other.value) ||
        (other.value < 0 && this->value < INT_MIN - other.value))
    {
        std::cout << RED << "Addition overflow detected" << RESET << std::endl;
        result.value = 0;
    }
    else
    {
        result.value = this->value + other.value;
    }
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    if ((other.value < 0 && this->value > INT_MAX + other.value) ||
        (other.value > 0 && this->value < INT_MIN + other.value))
    {
        std::cout << RED << "Subtraction overflow detected" << RESET << std::endl;
        result.value = 0;
    }
    else
    {
        result.value = this->value - other.value;
    }
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    if (this->value != 0 && other.value != 0)
    {
        long long temp = (long long)this->value * other.value;
        long long final_value = temp >> fractionalBits;

        if (final_value > INT_MAX || final_value < INT_MIN)
        {
            std::cout << RED << "Multiplication overflow detected" << RESET << std::endl;
            result.value = 0;
        }
        else
        {
            result.value = (int)final_value;
        }
    }
    else
    {
        result.value = 0;
    }
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    if (other.value != 0)
    {
        long long temp = (long long)this->value << fractionalBits;
        long long final_value = temp / other.value;

        if (final_value > INT_MAX || final_value < INT_MIN)
        {
            std::cout << RED << "Division overflow detected" << RESET << std::endl;
            result.value = 0;
        }
        else
        {
            result.value = (int)final_value;
        }
    }
    else
    {
        std::cout << RED << "Division by zero detected" << RESET << std::endl;
        result.value = 0;
    }
    return result;
}

Fixed &Fixed::operator++()
{
    this->value = value + 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->value += 1;
    return old;
}

Fixed &Fixed::operator--()
{
    this->value = value - 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->value -= 1;
    return old;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}