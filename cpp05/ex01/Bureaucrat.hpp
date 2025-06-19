#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
        Bureaucrat& operator=(const Bureaucrat& other);

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form& form);
    
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
