#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

class Template {
    private:

    public:
        Template();
        ~Template();
        Template(const Template& other);
        Template& operator=(const Template& other);

    class TemplateException : public std::exception {
        public:
            const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, const Template& obj);
#endif
