#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:

    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string formName, std::string target) const;
};

#endif
