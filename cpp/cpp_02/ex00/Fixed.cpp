#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called" <<std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &obj){
    std::cout << "Copy constructor called" << std::endl;
    this->value = obj.value;
}

Fixed& Fixed::operator=(const Fixed &obj){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &obj)
        return(*this);
    this->value = obj.value;
    return(*this);
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return(value);
}

void Fixed::setRawBits(int const raw){
    value = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}