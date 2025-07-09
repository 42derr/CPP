# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
    loadDatabase();
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    this->_btcPrices = other._btcPrices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_btcPrices = other._btcPrices;
    return *this;
}

void BitcoinExchange::loadDatabase() {
    std::ifstream dataFile("data.csv");
    if (!dataFile) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::getline(dataFile, line);
    while (std::getline(dataFile, line)) {
        size_t pos = line.find(',');
        std::string date = line.substr(0, pos);
        std::string price = line.substr(pos + 1);
        _btcPrices[date] = stringToDouble(price);
    }
}

void BitcoinExchange::loadInput(const std::string& input) {
    if (input.empty())
    {
        std::cerr << "Input can't be empty" << std::endl;
        return ;
    }
    std::ifstream inputFile(input.c_str());
    if (!inputFile) {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        size_t pos = line.find('|');
        if (isPipeFormatCorrect(line, pos) == false)
            continue;
        std::string date = line.substr(0, pos - 1);
        if (isValidDate(date) == false)
            continue;
        std::string value = line.substr(pos + 2);
        if (isValidValue(value) == false)
            continue;
        searchValue(date, stringToDouble(value));
    }
}

void BitcoinExchange::searchValue(const std::string& date, const double& value) {

    std::map<std::string, double>::const_iterator it = _btcPrices.lower_bound(date);

    if (it == _btcPrices.end()) {
        it = --_btcPrices.end();
    } else if (it->first != date) {
        if (it == _btcPrices.begin()) {
            std::cerr << "Error: no earlier date available.\n";
            return;
        }
        --it;
    }
    
    double price = it->second;
    double finalPrice = price * value;

    std::cout << it->first << " => " << value << " = " << finalPrice << '\n';
}


bool BitcoinExchange::isPipeFormatCorrect(const std::string& line, size_t pipePos) const {
    if (pipePos == std::string::npos || pipePos == 0 || pipePos + 1 >= line.size())
    {
        std::cerr << "Error: '|' not found or misplaced in the line." << std::endl;
        return false;
    }
    if (line[pipePos - 1] != ' ' || line[pipePos + 1] != ' ')
    {
        std::cerr << "Error: 'date | value'" << std::endl;
        return (false); 
    }
    return (true);
}

bool BitcoinExchange::validateDateFormat(const std::string& date) const {
    if (date.length() != 10)
        return (false);

    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 4; i++)
    {
        if (!std::isdigit(date[i]))
            return (false);
    }
    for (int i = 5; i < 7; i++)
    {
        if (!std::isdigit(date[i]))
            return (false);
    }
    for (int i = 8; i < 10; i++)
    {
        if (!std::isdigit(date[i]))
            return (false);
    }

    int month = stringToInt(date.substr(5, 2));
    int day = stringToInt(date.substr(8, 2));

    if (month < 1 || month > 12)
        return (false);

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day < 1 || day > daysInMonth[month - 1])
        return (false);

    return (true);
}


bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.empty())
    {
        std::cerr << "Error: date can't be empty" << std::endl;
        return (false);
    }
    if (validateDateFormat(date) == false)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }
    return (true);
}

bool BitcoinExchange::isValidNumber(const std::string& value) const {
    if (value.empty())
        return false;

    bool dot = false;
    size_t i = 0;

    if (value[i] == '-' || value[i] == '+')
    {
        i++;
        if (i == value.length())
            return (false);
    }

    for (; i < value.length(); i++)
    {
        if (value[i] == '.')
        {
            if (dot)
                return (false);
            dot = true;
            continue;
        }
        else if (!std::isdigit(value[i]))
            return (false);
    }
    return (true);
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    if (value.empty())
    {
        std::cerr << "Error: value can't be empty" << std::endl;
        return (false);
    }
    if (isValidNumber(value) == false)
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return (false);
    }
    double d = stringToDouble(value);
    if (d < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    else if (d > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false); 
    }
    return (true);
}

int BitcoinExchange::stringToInt(const std::string& str) const{
    return std::atoi(str.c_str());
}

double BitcoinExchange::stringToDouble(const std::string& str) const{
    double d;

    std::stringstream ss(str);
    ss >> d;
    return d;
}