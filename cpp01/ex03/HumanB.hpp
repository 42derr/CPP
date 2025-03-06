#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *current_weapon;
    public:
        HumanB(std::string human_name);
        ~HumanB();
        void setWeapon(Weapon& weapon);
        void attack(void);
};

#endif