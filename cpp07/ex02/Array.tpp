#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : array_size(0), array(new T[0]) {
    // std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array_size(n), array(new T[n]) {
    // std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
    // std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& other): array_size(other.array_size), array(new T[other.array_size]){
    for (unsigned int i = 0; i < array_size; i++)
        this->array[i] = other.array[i];
    // std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other)
        return *this;
    delete[] array;
    array_size = other.array_size;
    array = new T[array_size];
    for (unsigned int i = 0; i < array_size; i++)
        array[i] = other.array[i];
    // std::cout << "Array copy assignment operator called" << std::endl;
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= array_size) {
        throw std::out_of_range("Index is out of bounds");
    }
    return array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const{
    return array_size;
}

#endif

