# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other){
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    std::cout << "PmergeMe copy assignment operator called" << std::endl;
    return *this;
}

void PmergeMe::printOutput(){
    std::cout << "Before: " << _before << std::endl;
    std::cout << "After: " << _after << std::endl;
    std::cout << "Time to process a range of " << _number <<  " elements with std::vector : "<< _timeVec << std::endl;
    std::cout << "Time to process a range of " << _number <<  " elements with std::deque : "<< _timeDeq << std::endl;
}

void PmergeMe::isNumberValid(const std::string& number) {
    if (number.find_first_not_of("1234567890 ") != std::string::npos)
        throw std::runtime_error("Error: invalid character found — only digits are allowed");
}

void PmergeMe::initContainer() {
    std::stringstream ss(_before);
    int token;
    while (ss >> token) {
        _vec.push_back(token);
        _deq.push_back(token);
        _number++;
    }
}

void PmergeMe::sortVector() {
    std::clock_t start = std::clock();
    std::clock_t end = std::clock();

    _timeVec = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeque() {
    std::clock_t start = std::clock();
    std::clock_t end = std::clock();

    _timeDeq = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::loadNumber(const std::string number) {
    isNumberValid(number);
    _before = number;
    initContainer();


}

// clean all after use