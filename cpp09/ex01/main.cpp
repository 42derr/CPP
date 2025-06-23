#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage : ./RPN \"\"inverted Polish mathematical expression" << std::endl;
        return (1);
    }

    try {
        RPN rpn;

        rpn.loadExpression(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr <<  e.what() << std::endl;
    }
    return 0;
}

/*
    $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
    42
    $> ./RPN "7 7 * 7 -"
    42
    $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
    0
    $> ./RPN "(1 + 1)"
    Error
    $>
*/
