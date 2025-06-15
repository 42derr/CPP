#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat a("Aaron", 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Aaron: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bryant", 151);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Bryant: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Clark", 1);
        Bureaucrat d("Daniel", 150);
        Bureaucrat e("Edward", 50);

        try {
            c.incrementGrade();
        }
        catch (const std::exception& e) {
            std::cerr << "Error incrementing Clark's grade: " << e.what() << std::endl;
        }

        try {
            d.decrementGrade();
        }
        catch (const std::exception& e) {
            std::cerr << "Error decrementing Daniel's grade: " << e.what() << std::endl;
        }

        // Successfully increment Edward's grade three times
        e.incrementGrade();
        e.incrementGrade();
        e.incrementGrade();

        std::cout << e << std::endl;

        // Successfully decrement Edward's grade four times
        e.decrementGrade();
        e.decrementGrade();
        e.decrementGrade();
        e.decrementGrade();

        std::cout << e << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating or modifying Bureaucrats: " << e.what() << std::endl;
    }

    return 0;
}
