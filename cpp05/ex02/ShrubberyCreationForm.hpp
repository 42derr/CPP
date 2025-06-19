#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <cstdio>
# include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        void executeAction() const;
};

#endif
