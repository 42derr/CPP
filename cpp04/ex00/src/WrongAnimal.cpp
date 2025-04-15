# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("default") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}


WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this == &other)
        return *this;

    type = other.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const{
    std::cout << "I Don't know who am i" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return this->type;
}