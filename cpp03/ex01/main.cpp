#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating ScavTrap objects..." << std::endl;

    // Default constructor test
    ScavTrap scav1;
    std::cout << std::endl;

    // Parameterized constructor test
    ScavTrap scav2("SC4V-TP");
    std::cout << std::endl;

    // Copy constructor test
    ScavTrap scav3(scav2);
    std::cout << std::endl;

    // Copy assignment operator test
    ScavTrap scav4;
    scav4 = scav2;
    std::cout << std::endl;

    // Attack test
    scav2.attack("Enemy");
    std::cout << std::endl;

    // Energy depletion test
    for (int i = 0; i < 10; i++) { // Depleting energy
        scav2.attack("Dummy");
    }
    std::cout << std::endl;

    // Guard Gate mode test
    scav2.guardGate();
    std::cout << std::endl;

    // Destructor calls (will be automatically tested when objects go out of scope)
    std::cout << "Exiting main and destroying objects..." << std::endl;
    
    return 0;
}
