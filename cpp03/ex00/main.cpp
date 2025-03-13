#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap instance
    ClapTrap claptrap("CL4P-TP");

    // Test attacks
    claptrap.attack("Target-1");
    claptrap.attack("Target-2");

    // Test taking damage
    claptrap.takeDamage(3);
    claptrap.takeDamage(5);
    
    // Test repairing
    claptrap.beRepaired(4);
    
    // Test attacking until energy runs out
    for (int i = 0; i < 10; i++) {
        claptrap.attack("Dummy Target");
    }

    // Try to attack with no energy
    claptrap.attack("Out of Energy Target");

    // Try to repair with no energy
    claptrap.beRepaired(5);

    // Take enough damage to destroy it
    claptrap.takeDamage(15);
    
    // Attack ClapTrap after the hitpoint is 0
    claptrap.takeDamage(1);

    // Try to attack when destroyed
    claptrap.attack("Final Attempt");

    return 0;
}
