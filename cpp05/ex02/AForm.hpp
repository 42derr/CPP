#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
        AForm& operator=(const AForm& other);
    public:
        AForm();
        AForm(std::string name, int signGrade, int executeGrade);
        virtual ~AForm();
        AForm(const AForm& other);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getSignGrade(void) const;
        int getExecuteGrade(void) const;
        virtual void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;

    class NotSignedException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
        private:
            std::string message;
        public:
            GradeTooHighException(const std::string& message);
            ~GradeTooHighException() throw();
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        private:
            std::string message;
        public:
            GradeTooLowException(const std::string& message);
            ~GradeTooLowException() throw();
            const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
