#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        AMateria* dropped[100];
        int droppedCount;
    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
