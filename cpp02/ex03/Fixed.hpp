#ifndef FIXED_HPP
# define FIXED_HPP

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

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void); 
        Fixed operator--(int);

        static Fixed& min(Fixed& first, Fixed& second);
        static const Fixed& min(const Fixed& first, const Fixed& second);
        static Fixed& max(Fixed& first, Fixed& second);
        static const Fixed& max(const Fixed& first, const Fixed& second);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
