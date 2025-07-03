# include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _number(0), _comparison(0){
    std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _deq(other._deq), _before(other._before)
, _after(other._after), _timeVec(other._timeVec), _timeDeq(other._timeDeq), _number(other._number), _comparison(other._comparison){    
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    std::cout << "PmergeMe copy assignment operator called" << std::endl;
    _vec = other._vec;
    _deq = other._deq;
    _before = other._before;
    _after = other._after;
    _timeVec = other._timeVec;
    _timeDeq = other._timeDeq;
    _number = other._number;
    _comparison = other._comparison;
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
    _comparison = 0;
}

void PmergeMe::printOutput(){
    std::cout << "Before: " << _before << std::endl;
    // std::cout << "After: " << _after << std::endl;
    std::cout << std::endl << "After: ";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << std::endl << std::endl 
    ;
    std::cout << "Comparison: " << _comparison << std::endl << std::endl;

    // print comparission needed
    std::cout << "Time to process a range of " << _number <<  " elements with std::vector : "<< _timeVec << std::endl;
    // std::cout << "Time to process a range of " << _number <<  " elements with std::deque : "<< _timeDeq << std::endl;
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

void  PmergeMe::swapMultiple(size_t pos1, size_t pos2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::swap(_vec[pos1 - i], _vec[pos2 - i]);
    }
}

int PmergeMe::recursivePairing(int size, std::vector<int>::iterator it) {
    if ((size_t) size * 2 > _vec.size())
        return (size / 2);

    _comparison++;
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
        // WARNING THIS SHOULD RESPECT THE BOUND STILL ALTHOUGH INSERTED FROM THE BACK SKIP THE END(?)
        int no_pair = pend_end - pend_start + 1 / groupSize;        

        int bound = 0;
        if (((pend_end + 1) / groupSize) % 2 == 0)
            bound = 1;

        // fail on 15

        for (int i = 0; i < no_pair; i++)
        {
            int cur_pos = pend_end;
            int cur_number =_vec[cur_pos];
            int main_pos = 0 + groupSize - 1 ;
            int main_number = _vec[main_pos] ;

            // while (cur_number > main_number)
            // {
            //     main_pos = main_pos + groupSize;
            //     main_number = _vec[main_pos] ;
            //     if ((size_t)main_pos > pend_start - 1)
            //     {
            //         main_pos = pend_start + groupSize - 1;
            //         break ;
            //     }
            // }

            int max_try = (pend_start / groupSize) - bound;
            int k = 0;
            bool insert = false;

            while (k < max_try)
            {
                _comparison++;
                if (cur_number <= main_number)
                {

                    insert = true;
                    break;
                }

                main_pos += groupSize;
                main_number = _vec[main_pos];
                k++;
            }

            if (insert == false)
            {
                main_pos = pend_start - 1 + groupSize - 1;
                bound++;
            }

            bound++;

            copyMultiple(main_pos - (groupSize - 1) , cur_pos - (groupSize - 1), groupSize);
            pend_start += groupSize;

            if (pend_start > pend_end)
                return (1);
        }
        return (1);
    }
    return (0);
}

    // while (cur_number > main_number)
    // {
    //     main_pos = main_pos + groupSize;
    //     main_number = _vec[main_pos] ;
    //     if ((size_t)main_pos > pend_start - 1)
    //     {
    //         main_pos = pend_start + groupSize - 1;
    //         break ;
    //     }
    // }


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

            bool inserted = false;

            for (size_t m = 0; m < jacobBound; ++m) {
                size_t comparePos = (1 + m) * groupSize - 1;
                int compareMax = _vec[comparePos];

                _comparison++;
                if (compareMax >= currentMax) {
                    copyMultiple(comparePos - (groupSize - 1), currentPos - (groupSize - 1), groupSize);
                    pend_start += groupSize;
                    inserted = true;
                    break;
                }
            }

            if (!inserted) {
                copyMultiple(jacobBound * groupSize, currentPos - (groupSize - 1), groupSize);
                pend_start += groupSize;
            }

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
    std::cout << std::endl;
    std::clock_t end = std::clock();

    _timeVec = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeque() {
    std::clock_t start = std::clock();
    std::clock_t end = std::clock();

    _timeDeq = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::checkSorted() {
    if (std::is_sorted(_vec.begin(), _vec.end()))
        std::cout << "SUCCESS" << std::endl;
    else
        std::cout << "FAIL" << std::endl;
}

void PmergeMe::loadNumber(const std::string number) {
    isNumberValid(number);
    _before = number;
    initContainer();
    sortVector();
    checkSorted();
    printOutput();
    cleanAll();
}

