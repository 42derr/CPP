#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string zombie);
        ~Zombie();
        void setName(std::string zombie);
        void announce( void );
};

Zombie* zombieHorde(int N, std::string name);

#endif