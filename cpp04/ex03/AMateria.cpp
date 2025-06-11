# include "AMateria.hpp"

AMateria::AMateria(): type("default") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other): type(other.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this == &other)
        return *this;

    type = other.type;
    std::cout << "AMateria copy assignment operator called" << std::endl;
    return *this;
}

AMateria::AMateria(std::string const & type): type(type) {
    std::cout << "AMateria constructor called type : " << this->type << std::endl;
}

std::string const & AMateria::getType() const{
    return this->type;
}

void AMateria::use(ICharacter& target){
    if (getType() == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (getType() == "ice")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

