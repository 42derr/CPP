# include "harl.hpp"

Harl::Harl() {
    complaints[0] = &Harl::debug;
    complaints[1] = &Harl::info;
    complaints[2] = &Harl::warning;
    complaints[3] = &Harl::error;
};

Harl::~Harl() {};

void Harl::debug( void ) {
    std::cout << "DEBUG: " << "I love having extra bacon for my  7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "INFO: " << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "WARNING: " << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "ERROR: " << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
    int index;

    if (level == "DEBUG")
        index = 0;
    else if (level == "INFO")
        index = 1;
    else if (level == "WARNING")
        index = 2;
    else if (level == "ERROR")
        index = 3;
    else
    {
        std::cout << "Sorry, level not found!" << std::endl;
        return ;
    }
    (this->*complaints[index])();
}
