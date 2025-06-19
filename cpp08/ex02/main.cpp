#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterate through MutantStack elements: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
