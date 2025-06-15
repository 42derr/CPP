# include "Form.hpp"

Form::Form(): name("default"), isSigned(false), signGrade(50), executeGrade(50){
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade){
    if (this->signGrade < 1)
        throw GradeTooHighException("signGrade");
    else if (this->signGrade > 150)
        throw GradeTooLowException("signGrade");
    if (this->executeGrade < 1)
        throw GradeTooHighException("executeGrade");
    else if (this->executeGrade > 150)
        throw GradeTooLowException("executeGrade");
    std::cout << "Form constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade){
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this == &other)
        return *this;
    std::cout << "Form copy assignment operator called" << std::endl;
    std::cout << "No copy logic implemented because 'name', 'signGrade', 'executeGrade' is a const member" << std::endl;
    return *this;
}

std::string Form::getName(void) const{
    return this->name;
}

bool Form::getIsSigned(void) const {
    return this->isSigned;
}

int Form::getSignGrade(void) const {
    return this->signGrade;
}

int Form::getExecuteGrade(void) const {
    return this->executeGrade;
}

void  Form::beSigned(Bureaucrat& bureaucrat) {
    if (this->signGrade >= bureaucrat.getGrade())
        this->isSigned = true;
    else
        throw Form::GradeTooLowException("bureaucrat grade");
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(const std::string& message) : message(message + " is too high") {};

const char* Form::GradeTooHighException::what() const throw() {
    return message.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(const std::string& message) : message(message + " is too low") {};

const char* Form::GradeTooLowException::what() const throw() {
    return message.c_str();
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << "Form name: " << obj.getName() << std::endl
       << "Sign status: " << obj.getIsSigned() << std::endl
       << "required sign grade: " << obj.getSignGrade() << std::endl
       << "required execute grade: " << obj.getExecuteGrade();
    return os;
}

