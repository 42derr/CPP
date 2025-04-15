#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap " << this->name << " default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
};

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hitPoints(other.hitPoints), 
energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other)
        return *this;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ClapTrap " << name << " copy assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    
    this->energyPoints -= 1;

    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }

    if (this->hitPoints >= amount)
        this->hitPoints -= amount;
    else
        this->hitPoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;

    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
        return;
    }

    this->hitPoints += amount;
    this->energyPoints -= 1;

    std::cout << "ClapTrap " << name << " regains " << amount << " hit points!" << std::endl;
}