#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* newZom = new Zombie(name);
    
    return newZom;
}