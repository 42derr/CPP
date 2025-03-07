#include <iostream>
#include "Point.hpp"

void test(Point const a, Point const b, Point const c, Point const p, bool expected) {
    bool result = bsp(a, b, c, p);
    std::cout << "Point (" << p.getX() << ", " << p.getY() << ") is ";
    if (result)
        std::cout << "inside";
    else
        std::cout << "outside";
    std::cout << " the triangle. Expected: " << (expected ? "inside" : "outside") << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // **5 True Cases (inside the triangle)**
    test(a, b, c, Point(5, 5), true);
    test(a, b, c, Point(3, 2), true);
    test(a, b, c, Point(6, 3), true);
    test(a, b, c, Point(4, 4), true);
    test(a, b, c, Point(5, 6), true);

    // **3 False Cases (outside the triangle)**
    test(a, b, c, Point(11, 5), false);
    test(a, b, c, Point(-1, -1), false);
    test(a, b, c, Point(6, 11), false);

    // **2 Edge Cases (on the edge)**
    test(a, b, c, Point(5, 0), false);  // On bottom edge
    test(a, b, c, Point(2.5, 5), false);  // On left edge

    return 0;
}
