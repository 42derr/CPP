#include <iostream>
#include <vector>
#include <deque>
#include <list> 
#include <exception>
#include "easyfind.hpp"

int main()
{
    std::cout << "#####Testing Vector#####" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        easyfind(vec, 3);
        easyfind(vec, 10);
    }
    catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    std::cout << std::endl << "#####Testing deque#####" << std::endl;
    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
    deq.push_back(50);

    try {
        easyfind(deq, 20);
        easyfind(deq, 100);
    }
    catch (const std::exception& e) {
        std::cout << "Deque: " << e.what() << std::endl;
    }

    std::cout<< std::endl << "#####Testing List#####" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);

    try {
        easyfind(lst, 15);
        easyfind(lst, -1);
    }
    catch (const std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    return 0;
}
