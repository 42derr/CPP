# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
    // clean all container after use
    std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other){
    (void) other;
    // implement later
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    (void) other;
    // implement later
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

void  PmergeMe::swapMultiple(size_t pos1, size_t pos2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::swap(_vec[pos1 - i], _vec[pos2 - i]);
    }
}

int PmergeMe::recursivePairing(int size, std::vector<int>::iterator it) {
    if ((size_t) size * 2 > _vec.size())
        return (size / 2);

    if (it - _vec.begin() >= size && *it < *(it - size))
        swapMultiple(it - _vec.begin() , (it - size - _vec.begin()), size);

    size_t next = (it - _vec.begin() + size * 2);
    if (next <= _vec.size())
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

size_t indexJacobsthal(size_t max_value) {
    size_t j0 = 0;
    size_t j1 = 1;
    size_t jn = 1;
    size_t n = 1;

    while (true) {
        jn = j1 + 2 * j0;
        size_t diff = jn - j1;
        if (diff > max_value)
            break;
        j0 = j1;
        j1 = jn;
        n++;
    }

    return n - 1;
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

void PmergeMe::insertPendIntoMain(
    size_t main_start,
    size_t main_end,
    size_t pend_start,
    size_t pend_end,
    size_t groupSize
) {
    (void) main_start;
    size_t numPairs = (pend_end - pend_start + 1) / (2 * groupSize);

    for (size_t i = 0; i < numPairs; i++){
        size_t copyFrom = pend_start + groupSize;
        copyMultiple(main_end + 1, copyFrom, groupSize);
        pend_start += groupSize * 2;
        main_end += groupSize;
    }

    pend_start = main_end + 1;

    size_t pend_size = (pend_end - pend_start + 1) / groupSize;
    
    size_t jacobsthalIndex = indexJacobsthal(pend_size); // first useful is 3 because 1-1 = 0
    size_t jacobsthalInsert = insertJacobsthal(jacobsthalIndex) - insertJacobsthal(jacobsthalIndex - 1); // check negative

    // check 3 
    // while (pend_start != pend_end)
    // {
    //     bool changed = false;
    //     int current = _vec[pend_start + groupSize - 1];
    //     for (size_t i = 0; i < jacobsthalIndex; i++)
    //     {
    //         int compare = _vec[i * groupSize - 1];
    //         if (compare > current)
    //         {
    //             copyMultiple(i * groupSize - 1, pend_start + groupSize - 1, groupSize);
    //             changed = true;
    //         }
    //     }
    //     if (changed == false)
    //     {
    //         copyMultiple(main_end, pend_start + groupSize - 1, groupSize);
    //     }
    //     if (current);
    // }

    std::cout << main_start << std::endl;
    std::cout << main_end << std::endl;
    std::cout << pend_start << std::endl;
    std::cout << pend_end << std::endl;
    std::cout << jacobsthalIndex << std::endl;
    std::cout << jacobsthalInsert << std::endl;

    // use that number move pend to main

    // MOVE all A to main
    return ;

}

void PmergeMe::initializeMainAndPend(size_t groupSize) {
    if (groupSize < 1 || _vec.size() / groupSize <= 2) {
        initializeMainAndPend(groupSize / 2) ;
        return ;
    }
    size_t main_start = 0;
    size_t main_end = groupSize * 2 - 1;
    size_t leftoverCount = _vec.size() % groupSize;
    size_t pend_start = groupSize * 2;
    size_t pend_end = _vec.size() - leftoverCount - 1;

    insertPendIntoMain(main_start, main_end, pend_start, pend_end, groupSize);
    return ;
    initializeMainAndPend(groupSize / 2) ;
}

void PmergeMe::sortVector() {
    // std::clock_t start = std::clock();
    // std::clock_t end = std::clock();

    // _timeVec = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    if (_vec.size() <= 1)
        return ;
    int max = recursivePairing(1, _vec.begin() + 1);
    initializeMainAndPend((size_t) max);
    std::cout << "after" << std::endl;
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
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
    sortVector();

}
// // Insert 25 at index 2
// vec.insert(vec.begin() + 2, 25); // now: 10 20 25 30 40 50

// // Remove 30 (now at index 3)
// vec.erase(vec.begin() + 3);      // now: 10 20 25 40 50'

// for (std::vector<int>::iterator it = vec.begin(); it != vec.begin() + 3; ++it) {
//     std::cout << *it << "\n";
// }

// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
//     std::cout << *it << "\n";
// }

