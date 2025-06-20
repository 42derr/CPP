#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdio>
# include <fstream>
# include <map>
# include <sstream>
# include <cctype>
# include <cstdlib>

int stringToInt(const std::string& str);
double stringToDouble(std::string str);
int loadDatabase(std::map<std::string, double>& btcPrices);
int checkPipe(size_t pos, std::string str);
int validateDate(const std::string& date);
int checkDate(std::string date);
int checkNumber(const std::string& value);
int checkValue(std::string value);
void searchValue(const std::map<std::string, double>& btcPrices, const std::string& date, double value);
int loadInput(std::map<std::string, double>& btcPrices, std::string input);

#endif
