# include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& other){
    (void) other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    if (this == &other)
        return *this;
    (void) other;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
    int index = 0;

    std::string formOptions[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    while (index < 3 && formOptions[index] != formName)
        index++;

    switch(index)
    {
        case 0:
            std::cout << "Intern creates " << "ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << "RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << "PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cerr << "Error: The provided form name '" << formName << "' does not exist." << std::endl;
            std::cerr << "avaiable option : shrubbery creation, robotomy request, presidential pardon" << std::endl;
            return NULL;
    }
}

