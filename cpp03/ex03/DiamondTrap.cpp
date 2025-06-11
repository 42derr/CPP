# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DefaultDia_clap_name"), ScavTrap("DefaultDia_clap_name", 1), FragTrap("DefaultDia_clap_name", 1)
{
    this->name = "DefaultDia";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " default constructor called" << std::endl;
    // std::cout << "HP: " << this->hitPoints 
    // << ", Energy: " << this->energyPoints 
    // << ", Attack: " << this->attackDamage << std::endl;
};

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name, 1), FragTrap(name, 1){
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
    // std::cout << "HP: " << this->hitPoints 
    // << ", Energy: " << this->energyPoints 
    // << ", Attack: " << this->attackDamage << std::endl;
};

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this == &other)
        return *this;
    
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;

    std::cout << "DiamondTrap " << this->name << " copy assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap name: " << this->name 
              << ", ClapTrap name: " << ClapTrap::name << std::endl;
}