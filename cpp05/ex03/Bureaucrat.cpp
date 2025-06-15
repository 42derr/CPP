# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade (1){
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
    if (this->grade < 1)
        throw GradeTooHighException();
    else if (this->grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this == &other)
        return *this;
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    std::cout << "No copy logic implemented because 'name' is a const member" << std::endl;
    return *this;
}

std::string Bureaucrat::getName(void) const {
    return this->name;
}

int Bureaucrat::getGrade(void) const {
    return this->grade;
}

void Bureaucrat::incrementGrade(void){
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->grade -= 1;
}

void Bureaucrat::decrementGrade(void){
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->grade += 1;
}

void Bureaucrat::signForm(AForm& AForm){
    try {
        AForm.beSigned(*this);
        std::cout << this->name << " signed " << AForm.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << this->name << " couldn’t sign " << AForm.getName() 
                  << " because "  << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form){
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << this->name << " couldn’t execute " << form.getName() 
                  << " because "  << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}
