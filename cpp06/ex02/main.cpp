#include "generate.hpp"
#include <iostream>

int main()
{
    // Create an array of Base pointers
    const int count = 10;
    Base* objects[count];

    // Generate random objects
    for (int i = 0; i < count; ++i)
        objects[i] = generate();

    // Identify each object using pointer-based identify()
    std::cout << "Identify by pointer:\n";
    for (int i = 0; i < count; ++i)
        identify(objects[i]);

    // Identify each object using reference-based identify()
    std::cout << "\nIdentify by reference:\n";
    for (int i = 0; i < count; ++i)
        identify(*objects[i]);

    // Clean up
    for (int i = 0; i < count; ++i)
        delete objects[i];

    return 0;
}
