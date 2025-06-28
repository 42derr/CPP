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

// ./PmergeMe "6 15 8 16 2 11 0 17 9 18 14 19 5 12 4 20 3 10 1 21 7 13"