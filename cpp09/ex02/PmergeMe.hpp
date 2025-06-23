#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        std::string _before;
        std::string _after;
        double _timeVec;
        double _timeDeq;
        int _number;
        void PmergeMe::isNumberValid(const std::string& exp);
        void PmergeMe::sortVector();
        void PmergeMe::sortDeque();
        void PmergeMe::printOutput();
        void PmergeMe::initContainer();

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void PmergeMe::loadNumber(const std::string number);

};

#endif

