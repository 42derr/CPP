#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        void attack(const std::string& target);

        void whoAmI(void);
};

#endif
