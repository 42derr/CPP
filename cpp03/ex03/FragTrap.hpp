#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
    private:

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(std::string name, int spes);
        ~FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);

        void highFivesGuys(void);
};

#endif
