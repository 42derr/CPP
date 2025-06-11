# include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    this->ideas = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->ideas;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
    *(this->ideas) = *(other.ideas);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this == &other)
        return *this;

    Animal::operator=(other);
    *(this->ideas) = *(other.ideas);
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}