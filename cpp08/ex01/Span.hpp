#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <limits>
# include <vector>

class Span {
    
    private:
        unsigned int max_capacity;
        std::vector<int> container;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int num);
        int shortestSpan(void) const;
        int longestSpan(void) const;
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class OutOfCapacityException : public std::exception {
        public:
            const char* what() const throw();
    };

    class NotEnoughNumbersInSpan : public std::exception {
        public:
            const char* what() const throw();
    };
};

#endif
