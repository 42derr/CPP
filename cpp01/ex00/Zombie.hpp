#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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