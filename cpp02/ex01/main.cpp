#include "Zombie.hpp"

int main(void){
    int ZOMBIE_NUMBER = 5;

    Zombie* horde = zombieHorde(ZOMBIE_NUMBER ,"ZombieHorde");

    for (int i = 0; i < ZOMBIE_NUMBER; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}