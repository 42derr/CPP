#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>
# include <algorithm> 
# include <vector>
# include <deque>
# include <iomanip>
#include <sys/time.h>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        std::string _before;
        std::string _after;
        double _timeVec;
        double _timeDeq;
        int _number;
        int _comparisonVec;
        int _comparisonDeq;
        
        void initContainer();
        void cleanAll();
        void isNumberValid(const std::string& number);
        void printManyNumber();
        void printLessFiveNumber();
        void printOutput();
        bool isSortedDeq();
        bool isSortedVec();
        void checkSorted();

        void swapMultiple(size_t pos1, size_t pos2, size_t size);
        void copyMultiple(size_t pos1, size_t pos2, size_t size);

        void sortVector();
        int recursivePairing(int size, std::vector<int>::iterator it);
        void initializeMainAndPend(size_t groupSize);
        void insertPendIntoMain(size_t pend_start, size_t pend_end, size_t groupSize);
        void insertAIntoMain(size_t& pend_start, size_t& pend_end, size_t groupSize);
        int insertOnePair(size_t& pend_start, size_t& pend_end, size_t& groupSize, size_t& jacobIndex);
        int insertNoPair(size_t& pend_start, size_t& pend_end, size_t& groupSize, size_t& jacobIndex);

        void sortDeque();
        void swapMultipleDeque(size_t pos1, size_t pos2, size_t size);
        void copyMultipleDeque(size_t pos1, size_t pos2, size_t size);
        int recursivePairingDeque(int size, std::deque<int>::iterator it);
        void initializeMainAndPendDeque(size_t groupSize);
        void insertPendIntoMainDeque(size_t pend_start, size_t pend_end, size_t groupSize);
        void insertAIntoMainDeque(size_t& pend_start, size_t& pend_end, size_t groupSize);
        int insertOnePairDeque(size_t& pend_start, size_t& pend_end, size_t& groupSize, size_t& jacobIndex);
        int insertNoPairDeque(size_t& pend_start, size_t& pend_end, size_t& groupSize, size_t& jacobIndex);
        

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void loadNumber(const std::string number);

};

#endif

