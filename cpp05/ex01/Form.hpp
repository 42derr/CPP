#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;
        Form& operator=(const Form& other);

    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade);
        ~Form();
        Form(const Form& other);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getSignGrade(void) const;
        int getExecuteGrade(void) const;
        void beSigned(Bureaucrat& bureaucrat);
    
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

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
