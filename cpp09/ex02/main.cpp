#include "PmergeMe.hpp"
#include <iostream>

int main()
{
    try {
        PmergeMe example();
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating PmergeMe: " << e.what() << std::endl;
    }
    return 0;
}
