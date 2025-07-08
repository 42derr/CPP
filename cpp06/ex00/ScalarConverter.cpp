# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void) other;
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this == &other)
        return *this;
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    return *this;
}

void toChar(double d)
{
    if (d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    unsigned char uc = static_cast<unsigned char>(d);
    if (std::isprint(uc)) {
        std::cout << "char: '" << uc << "'" << std::endl;
    }
    else {
        std::cout << "char: Non displayable" << std::endl;
    }
    return ;
}

void toInt(double d)
{
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
        return ;
    }
    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;
    return ;
}

void toDouble(double d)
{
    double c = std::floor (d);
    if (c != d)
        std::cout << "double: " << d << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void toFloat(double d)
{
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
        return ;
    }
    float f = static_cast<float>(d);
    float c = std::floor (f);
    if (c != f)
        std::cout << "float: " << f << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    return ;
}

bool isChar(std::string literal){
    if (literal.length() == 1) {
        unsigned char uc = static_cast<unsigned char>(literal[0]);
        if (std::isprint(uc) && !std::isdigit(uc))
        {
            toChar(static_cast<double>(uc));
            toInt(static_cast<double>(uc));
            toFloat(static_cast<double>(uc));
            toDouble(static_cast<double>(uc));
            return true;
        }
    }
    return false;
}

bool isPseudoLiteral(const std::string& literal) {
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (true);
    }
    else if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return (true);
    }
    else if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (true);
    }
    return false;
}

bool isValidNumber(const std::string& literal) {
    bool dot = false;
    bool digit_found = false;
    size_t i = 0;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    for (; i < literal.length(); i++) {
        char c = literal[i];

        if (std::isdigit(static_cast<unsigned char>(c))) {
            digit_found = true;
            continue;
        }
        else if (c == '.' && !dot) {
            dot = true;
            continue;
        }
        else if (c == 'f' && i == literal.length() - 1) {
            return true;
        }
        else {
            return false;
        }
    }
    return digit_found;
}

double stringToDouble(std::string str) {
    double d;

    std::stringstream ss(str);
    ss >> d;
    return d;
}

bool isNumber(std::string literal)
{
    if (!isValidNumber(literal))
        return false;

    try {
        double d = stringToDouble(literal);
        if (std::isinf(d))
            return false;
        toChar(d);
        toInt(d);
        toFloat(d);
        toDouble(d);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

void printImpossible(void)
{
    std::cout << "char: impossible" << std::endl
              << "int: impossible" << std::endl
              << "float: impossible" << std::endl
              << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string literal) {

    if (literal.empty())
    {
        std::cout << "Don't enter empty literal" << std::endl;
        return ;
    }
    if (isChar(literal))
        return ;
    else if (isPseudoLiteral(literal))
        return ;
    else if (isNumber(literal))
        return ;
    else
        printImpossible();
}

