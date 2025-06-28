#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>
# include <algorithm> 
# include <vector>
# include <deque>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        std::string _before;
        std::string _after;
        double _timeVec;
        double _timeDeq;
        int _number;
        
        void isNumberValid(const std::string& number);
        void sortVector();
        void sortDeque();
        void printOutput();
        void initContainer();
        int recursivePairing(int size, std::vector<int>::iterator it);
        void swapMultiple(size_t pos1, size_t pos2, size_t size);
        void initializeMainAndPend(size_t groupSize);
        void insertPendIntoMain(size_t pend_start, size_t pend_end, size_t groupSize);
        void copyMultiple(size_t pos1, size_t pos2, size_t size);
        void insertAIntoMain(size_t& pend_start, size_t& pend_end, size_t groupSize);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void loadNumber(const std::string number);

};

#endif

