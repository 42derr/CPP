# include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), signGrade(50), executeGrade(50){
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade){
    if (this->signGrade < 1)
        throw GradeTooHighException("signGrade");
    else if (this->signGrade > 150)
        throw GradeTooLowException("signGrade");
    if (this->executeGrade < 1)
        throw GradeTooHighException("executeGrade");
    else if (this->executeGrade > 150)
        throw GradeTooLowException("executeGrade");
    std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade){
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this == &other)
        return *this;
    std::cout << "AForm copy assignment operator called" << std::endl;
    return *this;
}

std::string AForm::getName(void) const{
    return this->name;
}

bool AForm::getIsSigned(void) const {
    return this->isSigned;
}

int AForm::getSignGrade(void) const {
    return this->signGrade;
}

int AForm::getExecuteGrade(void) const {
    return this->executeGrade;
}

void  AForm::beSigned(Bureaucrat& bureaucrat) {
    if (this->signGrade >= bureaucrat.getGrade())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException("bureaucrat grade");
}

void  AForm::execute(Bureaucrat const & bureaucrat) const {
    if (!this->getIsSigned())
        throw NotSignedException();
    if (this->getExecuteGrade() < bureaucrat.getGrade())
        throw GradeTooLowException("bureaucrat's grade ");
    this->executeAction();
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message) : message(message + " is too high") {};

const char* AForm::GradeTooHighException::what() const throw() {
    return message.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message) : message(message + " is too low") {};

const char* AForm::GradeTooLowException::what() const throw() {
    return message.c_str();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << "AForm name: " << obj.getName() << std::endl
       << "Sign status: " << obj.getIsSigned() << std::endl
       << "required sign grade: " << obj.getSignGrade() << std::endl
       << "required execute grade: " << obj.getExecuteGrade();
    return os;
}

