#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& current_weapon;
    public:
        HumanA(std::string human_name, Weapon& weapon);
        ~HumanA();
        void attack(void);
};

#endif
