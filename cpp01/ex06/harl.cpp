# include "harl.hpp"

Harl::Harl() {
    complaints[0] = &Harl::debug;
    complaints[1] = &Harl::info;
    complaints[2] = &Harl::warning;
    complaints[3] = &Harl::error;
};

Harl::~Harl() {};

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my  7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain( std::string level ) {
    int index;

    if (level.empty())
    {
        std::cout << "Level can't be empty" << std::endl;
        return ;
    }

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
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return ;
    }

    switch (index) {
        case 0:
            (this->*complaints[0])();
            /* fall through */
        case 1:
            (this->*complaints[1])();
            /* fall through */
        case 2:
            (this->*complaints[2])();
            /* fall through */
        case 3:
            (this->*complaints[3])();
            /* fall through */
        default:
            break;
    }
}
