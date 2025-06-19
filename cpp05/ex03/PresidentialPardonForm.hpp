#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string target;   
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        void executeAction() const;
    };

#endif
