# include "Span.hpp"

Span::Span(): max_capacity(100){
    // std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N): max_capacity(N){
    // std::cout << "Span constructor called" << std::endl;
}

Span::~Span() {
    // std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span& other): max_capacity(other.max_capacity), container(other.container){
    // std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    max_capacity = other.max_capacity;
    container = other.container;
    // std::cout << "Span copy assignment operator called" << std::endl;
    return *this;
}

void Span::addNumber(int num) {
    if (container.size() + 1 > max_capacity)
        throw OutOfCapacityException();
    container.push_back(num);
}

int Span::longestSpan(void) const {
    if (container.size() < 2)
        throw NotEnoughNumbersInSpan();

    int min = *std::min_element(container.begin(), container.end());
    int max = *std::max_element(container.begin(), container.end());

    return max - min;
}

int Span::shortestSpan(void) const {
    if (container.size() < 2)
        throw NotEnoughNumbersInSpan();

    std::vector<int> copy = container;
    std::sort(copy.begin(), copy.end());

    int minSpan = std::numeric_limits<int>::max();
    for (unsigned int i = 1; i < copy.size(); ++i) {
        int span = copy[i] - copy[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        if (container.size() >= max_capacity)
            throw OutOfCapacityException();
        container.push_back(*it);
    }
}

const char* Span::OutOfCapacityException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NotEnoughNumbersInSpan::what() const throw() {
    return "The span does not have enough numbers to compute a span.";
}

