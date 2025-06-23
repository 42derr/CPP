# include "RPN.hpp"

RPN::RPN(){
    // std::cout << "RPN default constructor called" << std::endl;
}

RPN::~RPN() {
    // std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN(const RPN& other){
    // std::cout << "RPN copy constructor called" << std::endl;
    this->_stk = other._stk;
}

RPN& RPN::operator=(const RPN& other) {
    if (this == &other)
        return *this;
    // std::cout << "RPN copy assignment operator called" << std::endl;
    this->_stk = other._stk;
    return *this;
}

void RPN::isExpressionValid(const std::string& exp) {
    if (exp.find_first_not_of("1234567890 +-*/") != std::string::npos)
        throw std::runtime_error("Error: invalid character found — only digits (0-9) and operators (+ - * /) are allowed");
}

void RPN::applyOperator(const char& token){
    if (_stk.size() < 2)
        throw std::runtime_error("Error: insufficient operands for operation");

    int second = _stk.top(); _stk.pop();
    int first = _stk.top(); _stk.pop();

    switch(token)
    {
        case ('+'):
            _stk.push(first + second);
            break;
        case ('-'):
            _stk.push(first - second);
            break;
        case ('/'):
            if (second == 0)
                throw std::runtime_error("Error: division by zero");
            _stk.push(first / second);
            break;
        case ('*'):
            _stk.push(first * second);
            break;
        default :
            throw std::runtime_error("Error: invalid token encountered");
    }
}

void RPN::applyOperands(const char& token){
    int num = token - 48;
    _stk.push(num);
}

void RPN::loadExpression(const std::string& exp) {
    if (exp.empty())
        throw std::runtime_error("Error: expression cannot be empty");
    isExpressionValid(exp);

    while (!_stk.empty()) {
    _stk.pop();
    }

    std::stringstream ss(exp);
    std::string token;
    while (ss >> token) {
        if (token.length() != 1)
            throw std::runtime_error("Error: token must be a single digit between 0 and 9");
        char cToken = token[0];
        if (std::isdigit(cToken)){
            applyOperands(cToken);
        }
        else {
            applyOperator(cToken);
        }
    }

    if (_stk.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }
    else {
        std::cout << "Result: " << _stk.top() << std::endl;
        _stk.pop();
    }
}
