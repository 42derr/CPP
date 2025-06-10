# include "Harl.hpp"

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

int hash_level(const std::string& s)
{
    int h = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        h = 31 * h + s[i];
    }
    int valid = (s == "DEBUG" || s == "INFO" || s == "WARNING" || s == "ERROR");
    int final_hash = h * valid;
    return final_hash;
}

void Harl::complain( std::string level ) {
    const  int debug = 64921139;
    const int info = 2251950;
    const int warning = 1842428796;
    const int error = 66247144;

    if (level.empty())
    {
        std::cout << "Level can't be empty" << std::endl;
        return ;
    }
    
    switch (hash_level(level)) {
        case (debug):
            (this->*complaints[0])();
            break;
        case (info):
            (this->*complaints[1])();
            break;
        case (warning):
            (this->*complaints[2])();
            break;
        case (error):
            (this->*complaints[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
