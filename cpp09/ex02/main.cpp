#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage : ./PmergeMe \"List of number\"" << std::endl;
        return (1);
    }
    try {
        PmergeMe number;

        number.loadNumber(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating PmergeMe: " << e.what() << std::endl;
    }
    return 0;
}
// ./PmergeMe "11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7"