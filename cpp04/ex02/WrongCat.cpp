# include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this == &other)
        return *this;

    WrongAnimal::operator=(other);
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "Wrong, meow" << std::endl;
}