#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0){
    std::cout << "default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    fixedPoint = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this == &other)
        return *this;
    std::cout << "Copy assignment operator called" << std::endl;
    fixedPoint = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPoint = raw;
}