#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int fixedPoint;
        static const int  fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
