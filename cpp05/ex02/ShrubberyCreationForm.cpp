# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target){
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this == &other)
        return *this;
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    return *this;
}

void ShrubberyCreationForm::executeAction(void) const{
    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << "Error opening outfile" << std::endl;
        return;
    }
    
    outfile <<
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n"
    << std::endl;
} 
