# include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("DefaultFrag"){
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap " << this->name << " default constructor called" << std::endl;
};

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
};

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this == &other)
        return *this;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "FragTrap " << name << " copy assignment operator called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " requests a high-five! ✋😃" << std::endl;
}
