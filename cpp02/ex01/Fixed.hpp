#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {
    private:
        int fixedPoint;
        static const int  fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int fixedPoint);
        Fixed(const float fixedPoint);
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
