#include "phoneBookUtils.hpp"

void handleSigInt(int sig)
{
    (void) sig;

    std::cout << std::endl << "Caught SIGINT, invalid inputs!" << std::endl;
    std::cout << "New input:" << std::endl;
}

void handleSigQuit(int sig)
{
    (void) sig;
    std::cout << std::endl << "Caught SIGQUIT, invalid inputs!" << std::endl;
    std::cout << "New input:" << std::endl;
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
    for (size_t j = i; j < phoneNumber.length(); ++j) {
        if (!std::isdigit(phoneNumber[j])) {
            std::cout << "Please enter phone number with digits only." << std::endl;
            return false;
        }
    }
    size_t digitCount = phoneNumber.length() - i;
    if (digitCount < 7) {
        std::cout << "Your phone number is too short." << std::endl;
        return false;
    } else if (digitCount > 15) {
        std::cout << "Your phone number is too long." << std::endl;
        return false;
    }
    return true;
}