# include "BitcoinExchange.hpp"

int stringToInt(const std::string& str) {
    return std::atoi(str.c_str());
}

double stringToDouble(std::string str) {
    double d;

    std::stringstream ss(str);
    ss >> d;
    return d;
}

int loadDatabase(std::map<std::string, double>& btcPrices) {
    std::ifstream dataFile("data.csv");
    if (!dataFile) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    std::string line;
    std::getline(dataFile, line);
    while (std::getline(dataFile, line)) {
        size_t pos = line.find(',');
        std::string date = line.substr(0, pos);
        std::string price = line.substr(pos + 1);
        btcPrices[date] = stringToDouble(price);
    }
    return (0);
}

int checkPipe(size_t pos, std::string str)
{
    if (pos == std::string::npos)
    {
        std::cerr << "Error: '|' not found in the line." << std::endl;
        return (1);
    }
    if (str[pos - 1] != ' ' || str[pos + 1] != ' ')
    {
        std::cerr << "Error: 'date | value'" << std::endl;
        return (1); 
    }
    return (0);
}

int validateDate(const std::string& date)
{
    if (date.length() != 10)
        return 1;

    if (date[4] != '-' || date[7] != '-')
        return 1;
    for (int i = 0; i < 4; i++)
    {
        if (!std::isdigit(date[i]))
            return 1;
    }
    for (int i = 5; i < 7; i++)
    {
        if (!std::isdigit(date[i]))
            return 1;
    }
    for (int i = 8; i < 10; i++)
    {
        if (!std::isdigit(date[i]))
            return 1;
    }

    int month = stringToInt(date.substr(5, 2));
    int day = stringToInt(date.substr(8, 2));

    if (month < 1 || month > 12)
        return 1;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day < 1 || day > daysInMonth[month - 1])
        return 1;

    return 0;
}


int checkDate(std::string date)
{
    if (date.empty())
    {
        std::cerr << "Error: date can't be empty" << std::endl;
        return (1);
    }
    if (validateDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (1);
    }
    return (0);
}

int checkNumber(const std::string& value){

    bool dot = false;
    size_t i = 0;

    if (value[i] == '-' || value[i] == '+')
    {
        i++;
        if (i == value.length())
            return 1;
    }

    for (; i < value.length(); i++)
    {
        if (value[i] == '.')
        {
            if (dot)
                return (1);
            dot = true;
            continue;
        }
        else if (!std::isdigit(value[i]))
            return (1);
    }
    return (0);
}

int checkValue(std::string value){
    if (value.empty())
    {
        std::cerr << "Error: value can't be empty" << std::endl;
        return (1);
    }
    if (checkNumber(value))
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return (1);
    }
    double d = stringToDouble(value);
    if (d < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (1);
    }
    else if (d > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (1); 
    }
    return (0);
}


// study this
void searchValue(const std::map<std::string, double>& btcPrices, const std::string& date, double value) {
    if (btcPrices.empty()) {
        std::cerr << "Error: no data available.\n";
        return;
    }

    std::map<std::string, double>::const_iterator it = btcPrices.lower_bound(date);

    if (it == btcPrices.end()) {
        it = --btcPrices.end();
    } else if (it->first != date) {
        if (it == btcPrices.begin()) {
            std::cerr << "Error: no earlier date available.\n";
            return;
        }
        --it;
    }
    
    double price = it->second;
    double finalPrice = price * value;

    std::cout << it->first << " => " << value << " = " << finalPrice << '\n';
}

int loadInput(std::map<std::string, double>& btcPrices, std::string input) {
    std::ifstream inputFile(input.c_str());
    if (!inputFile) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        size_t pos = line.find('|');
        if (checkPipe(pos, line))
            continue;
        std::string date = line.substr(0, pos - 1);
        if (checkDate(date))
            continue;
        std::string value = line.substr(pos + 2);
        if (checkValue(value))
            continue;
        searchValue(btcPrices, date, stringToDouble(value));
    }
    return (0);
}