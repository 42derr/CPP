#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating FragTrap objects ===" << std::endl;
    
    // Default constructor
    FragTrap frag1;
    
    // Parameterized constructor
    FragTrap frag2("FR4G-TP");

    // Copy constructor
    FragTrap frag3(frag2);

    // Copy assignment operator
    frag1 = frag2;

    std::cout << "\n=== Testing FragTrap abilities ===" << std::endl;

    // Attack test (inherited from ClapTrap)
    frag2.attack("Target Dummy");

    // Special ability: High Five
    frag2.highFivesGuys();

    std::cout << "\n=== Exiting main and destroying objects ===" << std::endl;

    return 0;
}
