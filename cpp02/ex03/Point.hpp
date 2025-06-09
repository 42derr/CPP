#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        const Fixed& getX(void) const;
        const Fixed& getY(void) const;
};

int getCrossProduct(Point const a, Point const b, Point const p);
bool bsp(Point const a, Point const b, Point const c, Point const point);
    
#endif
