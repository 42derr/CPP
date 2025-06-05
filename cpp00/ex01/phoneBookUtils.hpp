#ifndef PHONEBOOKUTILS_HPP
# define PHONEBOOKUTILS_HPP

# include <iostream>
# include <string>
# include <csignal>
# include <cstdlib>
# include "PhoneBook.hpp"

void handleSigInt(int sig);
void handleSigQuit(int sig);
std::string trim(const std::string& str);
bool isValidPhoneNumber(const std::string& phoneNumber);

#endif