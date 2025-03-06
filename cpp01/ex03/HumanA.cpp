# include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon& weapon): name(human_name), current_weapon(weapon){
    // std::cout << "Created Human A, Name: " << name << "Weapon: " << current_weapon.getType() << std::endl;
}

HumanA::~HumanA(){
    // std::cout << "Destroyed Human A, Name" << name << std::endl;
}

void HumanA::attack(void) {
    std::cout << name << " attacks with their " << current_weapon.getType() << std::endl;
}
