#include "Template.hpp"
#include <iostream>

int main()
{
    try {
        Template example();
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Template: " << e.what() << std::endl;
    }
    return 0;
}
