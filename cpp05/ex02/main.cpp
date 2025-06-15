#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- Creating Bureaucrats ---" << std::endl;
    Bureaucrat alice("Alice", 1);     // Can execute all
    Bureaucrat bob("Bob", 140);       // Can't execute robotomy or pardon
    Bureaucrat charlie("Charlie", 50); // Can sign & exec Shrubbery and Robotomy

    std::cout << "\n--- Creating Forms ---" << std::endl;
    ShrubberyCreationForm shrubForm("garden");
    RobotomyRequestForm robotForm("Marvin");
    PresidentialPardonForm pardonForm("Ford Prefect");

    std::cout << "\n--- Signing Forms ---" << std::endl;
    try {
        bob.signForm(shrubForm); // Should work (bob has grade 140, shrub requires 145 to sign)
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        charlie.signForm(robotForm); // Should work (charlie has grade 50, robot requires 72)
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bob.signForm(pardonForm); // Should fail (bob has 140, pardon requires 25)
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Executing Forms ---" << std::endl;

    try {
        bob.executeForm(shrubForm); // Should fail (bob can't exec grade 137, has 140)
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        charlie.executeForm(shrubForm); // Should work
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        charlie.executeForm(robotForm); // Should work and randomly robotomize
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.signForm(pardonForm); // Should work
        alice.executeForm(pardonForm); // Should work
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
