#include "Zombie.hpp"

Zombie::Zombie(std::string zombie){
    name = zombie;
    std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " is destroyed" << std::endl ;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl ;
}
