#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {
    // std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack(){
    // std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other): std::stack<T>(other){

    // std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
    if (this == &other)
        return *this;
    std::stack<T>::operator=(other);
    // std::cout << "MutantStack copy assignment operator called" << std::endl;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

#endif

