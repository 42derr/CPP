# include "HumanB.hpp"

HumanB::HumanB(std::string human_name): name(human_name), current_weapon(NULL){
    // std::cout << "Created Human B, Name: " << name << std::endl;
}

HumanB::~HumanB(){
    // std::cout << "Destroyed Human B, Name" << name << std::endl;
}

void HumanB::attack(void) {
    if (current_weapon)
        std::cout << name << " attacks with their " << current_weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}


void HumanB::setWeapon(Weapon& weapon) {
    current_weapon = &weapon;
}