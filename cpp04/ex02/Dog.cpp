# include "Dog.hpp"

Dog::Dog(): Animal() {
    this->type = "Dog";
    this->ideas = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->ideas;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    *(this->ideas) = *(other.ideas);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this == &other)
        return *this;

    Animal::operator=(other);
    *(this->ideas) = *(other.ideas);
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Woof woof" << std::endl;
}