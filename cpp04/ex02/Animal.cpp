# include "Animal.hpp"

Animal::Animal(): type("default") {
    std::cout << "Animal default constructor called" << std::endl;
}


Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this == &other)
        return *this;

    type = other.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

void Animal::makeSound() const{
    std::cout << "I Don't know who am i" << std::endl;
}

std::string Animal::getType(void) const{
    return this->type;
}