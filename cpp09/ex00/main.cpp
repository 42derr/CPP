#include "BitcoinExchange.hpp"

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

// make manual regex
int checkDate(std::string date)
{
    (void) date;
    // do it manual
    // static const std::regex dateRegex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    // if (std::regex_match(date, dateRegex) == false)
    // {
    //     std::cerr << "Error: bad input => " << date << std::endl;
    //     return (1);
    // }
    return (0);
}

// make manual regex
int checkValue(std::string value){
    // do it manual

    // static const std::regex valueRegex(R"( ^[+-]?(\d+(\.\d*)?|\.\d+)$)");
    // if (std::regex_match(value, valueRegex) == false)
    // {
    //     std::cerr << "Error: bad input => " << value << std::endl;
    //     return (1);
    // }

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
        // All keys are less than date, use last element
        it = --btcPrices.end();
    } else if (it->first != date) {
        if (it == btcPrices.begin()) {
            std::cerr << "Error: no earlier date available.\n";
            return;
        }
        --it; // move to closest lower key
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

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage : ./btc input.txt" << std::endl;
        return (1);
    }

    std::map<std::string, double> btcPrices;
    if (loadDatabase(btcPrices))
        return (1);
    if (loadInput(btcPrices, argv[1]))
        return (1);
    return (0);
}

/*
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
*/
