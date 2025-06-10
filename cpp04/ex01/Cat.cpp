# include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this == &other)
        return *this;

    Animal::operator=(other);
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}