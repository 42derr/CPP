# include "Template.hpp"

Template::Template() {
    std::cout << "Template default constructor called" << std::endl;
}

Template::~Template() {
    std::cout << "Template destructor called" << std::endl;
}

Template::Template(const Template& other){
    std::cout << "Template copy constructor called" << std::endl;
}

Template& Template::operator=(const Template& other) {
    if (this == &other)
        return *this;
    std::cout << "Template copy assignment operator called" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Template& obj) {
    os << "This is template";
    return os;
}
