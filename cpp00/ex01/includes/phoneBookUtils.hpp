#ifndef PHONEBOOKUTILS_HPP
# define PHONEBOOKUTILS_HPP

# include <iostream>
# include <string>
# include <csignal>
# include <cstdlib>
# include "phoneBook.hpp"

void handleSigInt(int sig);
void handleSigQuit(int sig);
void handleEOF(void);
std::string trim(const std::string& str);
bool isValidPhoneNumber(const std::string& phoneNumber);

#endif