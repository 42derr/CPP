# include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _number(0), _comparisonVec(0) , _comparisonDeq(0){
    // std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
    // std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _deq(other._deq), _before(other._before)
, _after(other._after), _timeVec(other._timeVec), _timeDeq(other._timeDeq), _number(other._number), _comparisonVec(other._comparisonVec) , _comparisonDeq(other._comparisonDeq){    
    // std::cout << "PmergeMe copy constructor called" << std::endl;
}

// 17 one fail
// dup numbers

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    // std::cout << "PmergeMe copy assignment operator called" << std::endl;
    _vec = other._vec;
    _deq = other._deq;
    _before = other._before;
    _after = other._after;
    _timeVec = other._timeVec;
    _timeDeq = other._timeDeq;
    _number = other._number;
    _comparisonVec = other._comparisonVec;
    _comparisonDeq = other._comparisonDeq;
    return *this;
}

void PmergeMe::cleanAll() {
    _vec.clear();
    _deq.clear();
    _before.clear();
    _after.clear();
    _timeVec = 0;
    _timeDeq = 0;
    _number = 0;
    _comparisonVec = 0;
    _comparisonDeq = 0;
}

void PmergeMe::printManyNumber() {
    std::cout << "Before:  ";

    std::stringstream output(_before);
    int num;

    for (int i = 0; i < 4 && output >> num; ++i) {
        std::cout << num << " ";
    }

    std::cout << "[...]" << std::endl;

    std::cout << "After:   ";

    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.begin() + 4; ++it) {
        std::cout << *it << ' ';
    }

    std::cout << "[...]" << std::endl;

}

void PmergeMe::printLessFiveNumber() {
    std::cout << "Before:  " << _before << std::endl;

    std::cout << "After:   ";

    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << std::endl;
}

void PmergeMe::printOutput(){
    std::cout << "Vector Comparison   : " << "F(" << _number << ") = " << _comparisonVec << std::endl;
    std::cout << "Deque Comparison    : " << "F(" << _number << ") = " << _comparisonDeq << std::endl;
    checkSorted();

    if (_vec.size() <= 5)
        printLessFiveNumber();
    else
        printManyNumber();

    std::cout << "Time to process a range of " << _number <<  " elements with std::vector : "<< _timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _number <<  " elements with std::deque : "<< _timeDeq << " us" << std::endl;
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

/**********************************************
 *                                            *
 *                  VECTOR                    *
 *                                            *
 **********************************************/

void  PmergeMe::swapMultiple(size_t pos1, size_t pos2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::swap(_vec[pos1 - i], _vec[pos2 - i]);
    }
}

int PmergeMe::recursivePairing(int size, std::vector<int>::iterator it) {
    if ((size_t) size * 2 > _vec.size())
        return (size / 2);

    _comparisonVec++;
    if (it - _vec.begin() >= size && *it < *(it - size))
    {
        swapMultiple(it - _vec.begin() , (it - size - _vec.begin()), size);
    }

    size_t next = (it - _vec.begin() + size * 2);
    if (next < _vec.size())
        return (recursivePairing(size, it + size * 2));
    size_t newSize = size * 2;
    size_t newPos = newSize * 2 - 1;
    return (recursivePairing(newSize, _vec.begin() + newPos));
}

void PmergeMe::copyMultiple(size_t insertPos, size_t copyFrom, size_t size) {
    std::vector<int> temp;
    for (size_t i = 0; i < size; ++i)
        temp.push_back(_vec[copyFrom + i]);

    _vec.insert(_vec.begin() + insertPos, temp.begin(), temp.end());

    size_t eraseStart = copyFrom >= insertPos ? copyFrom + size : copyFrom;
    _vec.erase(_vec.begin() + eraseStart, _vec.begin() + eraseStart + size);
}

size_t insertJacobsthal(size_t index) {
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;

    size_t j0 = 0;
    size_t j1 = 1;
    size_t jn = 1;

    for (size_t i = 2; i <= index; ++i) {
        jn = j1 + 2 * j0;
        j0 = j1;
        j1 = jn;
    }

    return jn;
}

void PmergeMe::insertAIntoMain(size_t& pend_start, size_t& pend_end, size_t groupSize) {
    size_t main_end = pend_start - 1;
    size_t numPairs = (pend_end - pend_start + 1) / (2 * groupSize);

    for (size_t i = 0; i < numPairs; i++){
        size_t a_pos = pend_start + groupSize;
        copyMultiple(main_end + 1, a_pos, groupSize);
        pend_start += groupSize * 2;
        main_end += groupSize;
    }
    pend_start = main_end + 1;
}

int PmergeMe::insertNoPair(
    size_t& pend_start,
    size_t& pend_end,
    size_t& groupSize,
    size_t& jacobIndex
) {
    if (pend_end - pend_start + 1 < groupSize * (insertJacobsthal(jacobIndex) - insertJacobsthal(jacobIndex - 1))) {
        int no_pair = pend_end - pend_start + 1 / groupSize;        
        
        int bound = 0;
        if (((pend_end + 1) / groupSize) % 2 == 0)
            bound = 1;

        for (int i = 0; i < no_pair; i++)
        {
            int cur_pos = pend_end;
            int cur_number =_vec[cur_pos];
            int max_try = (pend_start / groupSize) - bound;

            int left = 0;
            int right = max_try - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                size_t comparePos = (1 + mid) * groupSize - 1;
                int compareMax = _vec[comparePos];

                _comparisonVec++;
                if (compareMax < cur_number)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            if (right == max_try)
                bound++;
            bound++;

            copyMultiple(left * groupSize, cur_pos - (groupSize - 1), groupSize);

            pend_start += groupSize;

            if (pend_start > pend_end)
                return (1);
        }
        return (1);
    }
    return (0);
}

int PmergeMe::insertOnePair(
    size_t& pend_start,
    size_t& pend_end,
    size_t& groupSize,
    size_t& jacobIndex
) {
    int pend_size = (pend_end - pend_start + 1) / groupSize;

    if (pend_size < 2)
    {
        if (insertNoPair(pend_start, pend_end, groupSize, jacobIndex))
            return (1);
    }
    return (0);
}

void PmergeMe::insertPendIntoMain(
    size_t pend_start,
    size_t pend_end,
    size_t groupSize
) {
    insertAIntoMain(pend_start, pend_end, groupSize);

    size_t jacobIndex = 3;
    size_t jacobBound = insertJacobsthal(jacobIndex) + insertJacobsthal(jacobIndex - 1) - 1;

    if (insertOnePair(pend_start, pend_end, groupSize, jacobIndex))
        return ;

    while (true)
    {
        size_t insertCount = insertJacobsthal(jacobIndex) - insertJacobsthal(jacobIndex - 1);

        for (size_t k = 0; k < insertCount; ++k) {
            int currentPos = static_cast<int>(pend_start + groupSize * (insertCount - k) - 1);
            int currentMax = _vec[currentPos];

            int left = 0;
            int right = jacobBound - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                size_t comparePos = (1 + mid) * groupSize - 1;
                int compareMax = _vec[comparePos];

                _comparisonVec++;
                if (compareMax < currentMax)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            copyMultiple(left * groupSize, currentPos - (groupSize - 1), groupSize);
            pend_start += groupSize;

            if (pend_start > pend_end)
                return;
        }
        jacobIndex++;
        jacobBound = insertJacobsthal(jacobIndex) + insertJacobsthal(jacobIndex - 1) - 1;

        if (insertNoPair(pend_start, pend_end, groupSize, jacobIndex))
            return ;
    }
}

void PmergeMe::initializeMainAndPend(size_t groupSize) {
    if (groupSize == 0)
        return ;

    if (_vec.size() / groupSize <= 2)
    {
        initializeMainAndPend(groupSize / 2) ;
        return ;
    }
    
    size_t leftoverCount = _vec.size() % groupSize;
    size_t pend_start = groupSize * 2;
    size_t pend_end = _vec.size() - leftoverCount - 1;
    
    insertPendIntoMain(pend_start, pend_end, groupSize);
    initializeMainAndPend(groupSize / 2) ;
}

void PmergeMe::sortVector() {
    std::clock_t start = std::clock();

    if (_vec.size() <= 1)
        return ;

    int max = recursivePairing(1, _vec.begin() + 1);
    initializeMainAndPend((size_t) max);

    std::clock_t end = std::clock();
    _timeVec = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

/**********************************************
 *                                            *
 *                  DEQUE                     *
 *                                            *
 **********************************************/

void  PmergeMe::swapMultipleDeque(size_t pos1, size_t pos2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::swap(_deq[pos1 - i], _deq[pos2 - i]);
    }
}

int PmergeMe::recursivePairingDeque(int size, std::deque<int>::iterator it) {
    if ((size_t) size * 2 > _deq.size())
        return (size / 2);

    _comparisonDeq++;
    if (it - _deq.begin() >= size && *it < *(it - size))
    {
        swapMultipleDeque(it - _deq.begin() , (it - size - _deq.begin()), size);
    }

    size_t next = (it - _deq.begin() + size * 2);
    if (next < _deq.size())
        return (recursivePairingDeque(size, it + size * 2));
    size_t newSize = size * 2;
    size_t newPos = newSize * 2 - 1;
    return (recursivePairingDeque(newSize, _deq.begin() + newPos));
}

void PmergeMe::copyMultipleDeque(size_t insertPos, size_t copyFrom, size_t size) {
    std::vector<int> temp;
    for (size_t i = 0; i < size; ++i)
        temp.push_back(_deq[copyFrom + i]);

    _deq.insert(_deq.begin() + insertPos, temp.begin(), temp.end());

    size_t eraseStart = copyFrom >= insertPos ? copyFrom + size : copyFrom;
    _deq.erase(_deq.begin() + eraseStart, _deq.begin() + eraseStart + size);
}

void PmergeMe::insertAIntoMainDeque(size_t& pend_start, size_t& pend_end, size_t groupSize) {
    size_t main_end = pend_start - 1;
    size_t numPairs = (pend_end - pend_start + 1) / (2 * groupSize);

    for (size_t i = 0; i < numPairs; i++){
        size_t a_pos = pend_start + groupSize;
        copyMultipleDeque(main_end + 1, a_pos, groupSize);
        pend_start += groupSize * 2;
        main_end += groupSize;
    }
    pend_start = main_end + 1;
}

int PmergeMe::insertNoPairDeque(
    size_t& pend_start,
    size_t& pend_end,
    size_t& groupSize,
    size_t& jacobIndex
) {
    if (pend_end - pend_start + 1 < groupSize * (insertJacobsthal(jacobIndex) - insertJacobsthal(jacobIndex - 1))) {
        int no_pair = pend_end - pend_start + 1 / groupSize;        
        
        int bound = 0;
        if (((pend_end + 1) / groupSize) % 2 == 0)
            bound = 1;

        for (int i = 0; i < no_pair; i++)
        {
            int cur_pos = pend_end;
            int cur_number =_deq[cur_pos];
            int max_try = (pend_start / groupSize) - bound;

            int left = 0;
            int right = max_try - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                size_t comparePos = (1 + mid) * groupSize - 1;
                int compareMax = _deq[comparePos];

                _comparisonDeq++;
                if (compareMax < cur_number)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            if (right == max_try)
                bound++;
            bound++;

            copyMultipleDeque(left * groupSize, cur_pos - (groupSize - 1), groupSize);

            pend_start += groupSize;

            if (pend_start > pend_end)
                return (1);
        }
        return (1);
    }
    return (0);
}

int PmergeMe::insertOnePairDeque(
    size_t& pend_start,
    size_t& pend_end,
    size_t& groupSize,
    size_t& jacobIndex
) {
    int pend_size = (pend_end - pend_start + 1) / groupSize;

    if (pend_size < 2)
    {
        if (insertNoPairDeque(pend_start, pend_end, groupSize, jacobIndex))
            return (1);
    }
    return (0);
}

void PmergeMe::insertPendIntoMainDeque(
    size_t pend_start,
    size_t pend_end,
    size_t groupSize
) {
    insertAIntoMainDeque(pend_start, pend_end, groupSize);

    size_t jacobIndex = 3;
    size_t jacobBound = insertJacobsthal(jacobIndex) + insertJacobsthal(jacobIndex - 1) - 1;

    if (insertOnePairDeque(pend_start, pend_end, groupSize, jacobIndex))
        return ;

    while (true)
    {
        size_t insertCount = insertJacobsthal(jacobIndex) - insertJacobsthal(jacobIndex - 1);

        for (size_t k = 0; k < insertCount; ++k) {
            int currentPos = static_cast<int>(pend_start + groupSize * (insertCount - k) - 1);
            int currentMax = _deq[currentPos];

            int left = 0;
            int right = jacobBound - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                size_t comparePos = (1 + mid) * groupSize - 1;
                int compareMax = _deq[comparePos];

                _comparisonDeq++;
                if (compareMax < currentMax)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            copyMultipleDeque(left * groupSize, currentPos - (groupSize - 1), groupSize);
            pend_start += groupSize;

            if (pend_start > pend_end)
                return;
        }
        jacobIndex++;
        jacobBound = insertJacobsthal(jacobIndex) + insertJacobsthal(jacobIndex - 1) - 1;

        if (insertNoPairDeque(pend_start, pend_end, groupSize, jacobIndex))
            return ;
    }
}

void PmergeMe::initializeMainAndPendDeque(size_t groupSize) {
    if (groupSize == 0)
        return ;

    if (_deq.size() / groupSize <= 2)
    {
        initializeMainAndPendDeque(groupSize / 2) ;
        return ;
    }
    
    size_t leftoverCount = _deq.size() % groupSize;
    size_t pend_start = groupSize * 2;
    size_t pend_end = _deq.size() - leftoverCount - 1;
    
    insertPendIntoMainDeque(pend_start, pend_end, groupSize);
    initializeMainAndPendDeque(groupSize / 2) ;
}

void PmergeMe::sortDeque() {
    std::clock_t start = std::clock();

    if (_deq.size() <= 1)
        return ;

    int max = recursivePairingDeque(1, _deq.begin() + 1);
    initializeMainAndPendDeque((size_t) max);

    std::clock_t end = std::clock();
    _timeDeq = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

bool PmergeMe::isSortedVec() {
    for (size_t i = 1; i < _vec.size(); ++i) {
        if (_vec[i] < _vec[i - 1])
            return false;
    }
    return true;
}


bool PmergeMe::isSortedDeq() {
    for (size_t i = 1; i < _deq.size(); ++i) {
        if (_deq[i] < _deq[i - 1])
            return false;
    }
    return true;
}


void PmergeMe::checkSorted() {
    if (isSortedVec())
        std::cout << "VECTOR SUCCESS" << std::endl;
    else
        std::cout << "VECTOR FAIL" << std::endl;

    if (isSortedDeq())
        std::cout << "DEQUE SUCCESS" << std::endl;
    else
        std::cout << "DEQUE FAIL" << std::endl;
}

void PmergeMe::loadNumber(const std::string number) {
    if (number.empty())
    {
        std::cerr << "Input can't be empty" << std::endl;
        return;
    }
    isNumberValid(number);
    _before = number;
    initContainer();
    sortVector();
    sortDeque();
    printOutput();
    cleanAll();
}

