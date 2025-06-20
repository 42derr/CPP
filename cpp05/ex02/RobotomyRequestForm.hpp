#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string target;   
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        void executeAction() const;
};

#endif
