# include "Point.hpp"

int getCrossProduct(Point const a, Point const b, Point const p) {
    Fixed abX = b.getX() - a.getX();
    Fixed abY = b.getY() - a.getY();

    Fixed apX = p.getX() - a.getX();
    Fixed apY = p.getY() - a.getY();

    Fixed cross = (abX * apY) - (apX * abY);

    if (cross > Fixed(0))
        return 1;
    else if (cross < Fixed(0))
        return -1;
    else
        return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    int resultOne = getCrossProduct(a,b,point);
    int resultTwo = getCrossProduct(b,c,point);
    int resultThree = getCrossProduct(c,a,point);

    if (resultOne == 0 || resultTwo == 0 || resultThree == 0)
        return false;

    if ((resultOne == resultTwo) &&  (resultTwo == resultThree))
        return true;

    return false;
}
