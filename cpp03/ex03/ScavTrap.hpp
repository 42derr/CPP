#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    private:
        bool guard_gate;

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(std::string name, int spes);
        ~ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);

        void attack(const std::string& target);
        void guardGate(void);
};

#endif
