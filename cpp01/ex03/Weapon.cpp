# include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type){
    type = weapon_type;
    // std::cout << "A weapon is created with a type of " << type << std::endl;
}

Weapon::~Weapon(){
    // std::cout << "A weapon is destroyed with a type of " << type << std::endl;
}

std::string Weapon::getType(void) const {
    return type;
}

void Weapon::setType(const std::string& wtype) {
    type = wtype;
}