#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdio>
# include <fstream>
# include <map>
# include <sstream>
# include <cctype>
# include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, double> _btcPrices;
        bool validateDateFormat(const std::string& date) const;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& value) const;
        bool isValidNumber(const std::string& value) const;
        bool isPipeFormatCorrect(const std::string& line, size_t pipePos) const;
        int stringToInt(const std::string& str) const;
        double stringToDouble(const std::string& str) const;
        void searchValue(const std::string& date, const double& value);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void loadDatabase();
        void loadInput(const std::string& inputFile);

};

#endif
