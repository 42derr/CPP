# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target){
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this == &other)
        return *this;
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    std::cout << "No copy logic implemented because AForm have const member" << std::endl;
    return *this;

}

void RobotomyRequestForm::executeAction(void) const{
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int randomNumber = std::rand() % 2;

    if (randomNumber == 0)
    {
        std::cout
        << "*drilling noises* "
        << target 
        << " has been robotomized successfully!"
        << std::endl;
    }
    else
    {
        std::cout
        << "The robotomy failed on "
        << target 
        << std::endl;
    }
}

