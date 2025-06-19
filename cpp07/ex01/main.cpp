#include <iostream>
#include "iter.hpp"

void printInt(const int& x) {
    std::cout << x << std::endl;
}

void increment(int& x) {
    ++x;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << "Original array:\n";
    iter(arr, 5, printInt);
    iter(arr, 5, increment);

    std::cout << "After increment:\n";
    iter(arr, 5, printInt);

    const int carr[] = {10, 20, 30};
    std::cout << "Const array:\n";
    iter(carr, 3, printInt);

    // iter(carr, 3, increment);

    return 0;
}
