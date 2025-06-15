# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default"){
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target){
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target){
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this == &other)
        return *this;
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    std::cout << "No copy logic implemented because AForm have const member" << std::endl;
    return *this;
}

void PresidentialPardonForm::executeAction(void) const{
    std::cout
    << "Informs that "
    << target
    << " has been pardoned by Zaphod Beeblebrox."
    << std:: endl;
}

