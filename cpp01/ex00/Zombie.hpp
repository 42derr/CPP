#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string zombie);
        ~Zombie();
        void announce( void );
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif