#include "../includes/phoneBookUtils.hpp"

void handleSigInt(int sig)
{
    std::cout << std::endl << "Caught SIGINT, Exiting..." << std::endl;
    std::exit(128 + sig);
}

void handleSigQuit(int sig)
{
    std::cout << std::endl << "Caught SIGQUIT, Exiting..." << std::endl;
    std::exit(128 + sig);
}

void handleEOF(void)
{
    std::cout << std::endl << "Caught EOF, Exiting..." << std::endl;
    std::exit(0);
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\v\f");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r\v\f");
    return str.substr(first, last - first + 1);
}

bool isValidPhoneNumber(const std::string& phoneNumber) {
    size_t i = 0;
    if (phoneNumber[0] == '+') {
        i = 1;
    }
    if (phoneNumber.length() == i) {
        return false;
    }
    while (i < phoneNumber.length())
    {
        if (!std::isdigit(phoneNumber[i])) {
            std::cout << "Please enter phone number with digits only." << std::endl;
            return false;
        }
        i++;
    }
    return true;
}