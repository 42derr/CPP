#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someIntern;
    Bureaucrat boss("Boss", 1);      // Highest grade bureaucrat
    Bureaucrat junior("Junior", 150); // Lowest grade bureaucrat

    const char* formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "invalid form"
    };

    const int numForms = 4;

    for (int i = 0; i < numForms; ++i)
    {
        AForm* form = someIntern.makeForm(std::string(formNames[i]), "Target1");
        if (!form)
        {
            std::cout << "Failed to create form for: " << formNames[i] << std::endl << std::endl;
            continue;
        }

        std::cout << "\nTrying to sign and execute form: " << form->getName() << std::endl;

        try
        {
            boss.signForm(*form);
            boss.executeForm(*form);
        }
        catch (std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "Trying to execute with junior bureaucrat:" << std::endl;
        try
        {
            junior.executeForm(*form);
        }
        catch (std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        delete form;
        std::cout << std::endl;
    }

    return 0;
}
