# include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("DefaultScav"){
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->guard_gate = false;

    std::cout << "ScavTrap " << this->name << " default constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->guard_gate = false;

    std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string name, int spes): ClapTrap(name){
    (void) spes;
    this->energyPoints = 50;

    std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
};

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->guard_gate = other.guard_gate;
    std::cout << "ScavTrap " << name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this == &other)
        return *this;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->guard_gate = other.guard_gate;
    std::cout << "ScavTrap " << name << " copy assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target){
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    
    this->energyPoints -= 1;

    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    this->guard_gate = true;
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}