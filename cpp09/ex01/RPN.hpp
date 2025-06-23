#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>

class RPN {
    private:
        std::stack<int> _stk;
        void isExpressionValid(const std::string& exp);
        void applyOperator(const char& token);
        void applyOperands(const char& token);

    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        void loadExpression(const std::string& exp);
};

#endif
