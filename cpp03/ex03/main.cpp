#include "DiamondTrap.hpp"

int main() {
    std::cout << "Creating DiamondTrap DefaultDia...\n";
    DiamondTrap d1;  // Default constructor

    std::cout << "\nCreating DiamondTrap Alpha...\n";
    DiamondTrap d2("Alpha");  // Parameterized constructor

    
    std::cout << "\nCreating DiamondTrap Alpha2...\n";
    DiamondTrap d4("Alpha2");  // Parameterized constructor

    std::cout << "\nTesting attack function...\n";
    d2.attack("TargetBot");

    std::cout << "\nTesting take damage function...\n";
    d4.takeDamage(50);
    d4.takeDamage(50);

    std::cout << "\nTesting max energy function...\n";
    for (int i = 0; i < 101; i++) { // Depleting energy
        d1.attack("Dummy");
    }

    std::cout << "\nTesting whoAmI function...\n";
    d2.whoAmI();

    std::cout << "\nTesting Copy Constructor...\n";
    DiamondTrap d3(d2);  // Copy constructor

    std::cout << "\nTesting Copy Assignment Operator...\n";
    d1 = d2;  // Copy assignment

    std::cout << "\nExiting main function, destructors will be called...\n";
    return 0;
}
