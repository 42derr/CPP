#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    // own test
    std::cout << std::endl << "OWN TEST" << std::endl << std::endl; 
    Fixed x(5.05f);  // Calls the float constructor
    Fixed y(10);     // Calls the int constructor
    // Test comparison operators
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    // Test arithmetic operators
    Fixed add = x + y;
    Fixed sub = x - y;
    Fixed mul = x * y;
    Fixed div = x / y;

    std::cout << "x + y: " << add << std::endl;
    std::cout << "x - y: " << sub << std::endl;
    std::cout << "x * y: " << mul << std::endl;
    std::cout << "x / y: " << div << std::endl;

    // Test pre and post increment/decrement operators
    std::cout << "x++: " << x++ << " (post increment)" << std::endl;
    std::cout << "++x: " << ++x << " (pre increment)" << std::endl;
    std::cout << "x--: " << x-- << " (post decrement)" << std::endl;
    std::cout << "--x: " << --x << " (pre decrement)" << std::endl;

    // Test min and max functions
    Fixed& minFixed = Fixed::min(x, y);
    const Fixed& maxFixed = Fixed::max(x, y);

    std::cout << "min(x, y): " << minFixed << std::endl;
    std::cout << "max(x, y): " << maxFixed << std::endl;

    return 0;
}

/*
    0
    0.00390625
    0.00390625
    0.00390625
    0.0078125
    10.1016
    10.1016
*/
