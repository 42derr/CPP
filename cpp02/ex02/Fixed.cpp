#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0){
    std::cout << "default constructor called" << std::endl;
};

Fixed::Fixed(const int fixedPoint){
    this->fixedPoint = fixedPoint << fractionalBits;
    std::cout << "int constructor called" << std::endl;
};

Fixed::Fixed(const float fixedPoint){
    this->fixedPoint = static_cast<int>(roundf(fixedPoint * (1 << fractionalBits)));
    std::cout << "float constructor called" << std::endl;
};

Fixed::~Fixed(){
    std::cout << "destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) {
    fixedPoint = other.fixedPoint;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this == &other)
        return *this;
    fixedPoint = other.fixedPoint;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->fixedPoint >= other.fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->fixedPoint != other.fixedPoint;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;

    result.fixedPoint = this->fixedPoint + other.fixedPoint;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;

    result.fixedPoint = this->fixedPoint - other.fixedPoint;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;

    result.fixedPoint = (this->fixedPoint * other.fixedPoint) >> fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;

    result.fixedPoint = (this->fixedPoint << fractionalBits) / other.fixedPoint;
    return result;
}

Fixed& Fixed::operator++(void) {
    // this->fixedPoint += (1 << fractionalBits);
    this->fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    // this->fixedPoint += (1 << fractionalBits);
    this->fixedPoint += 1;
    return temp;
}

Fixed& Fixed::operator--(void) {
    // this->fixedPoint -= (1 << fractionalBits);
    this->fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--(int) { // how this work
    Fixed temp = *this;

    this->fixedPoint -= 1;
    // this->fixedPoint -= (1 << fractionalBits);
    return temp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    if (first.toFloat() < second.toFloat())
        return first;
    else
        return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    if (first.toFloat() < second.toFloat())
        return first;
    else
        return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    if (first.toFloat() > second.toFloat())
        return first;
    else
        return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    if (first.toFloat() > second.toFloat())
        return first;
    else
        return second;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPoint = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(this->fixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt( void ) const {
    return this->fixedPoint >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    float floatValue = obj.toFloat();

    os << floatValue;
    return os;
}
