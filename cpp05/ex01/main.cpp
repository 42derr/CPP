#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Form a("Survey a", 0, 50);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Survey a: " << e.what() << std::endl;
    }

    try {
        Form a("Survey a", 151, 50);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Survey a: " << e.what() << std::endl;
    }

    try {
        Form b("Survey b", 50, 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Survey b: " << e.what() << std::endl;
    }

    try {
        Form b("Survey b", 50, 151);
    }
    catch (const std::exception& e) {
        std::cerr << "Error creating Survey b: " << e.what() << std::endl;
    }

    try {
        Bureaucrat a("aaron", 60);
        Form c("Survey c", 50, 50);

        a.signForm(c);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("bruce", 50);
        Form c("Survey c", 50, 50);

        b.signForm(c);
        std::cout << c << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}
