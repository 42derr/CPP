#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

template <typename T>
class Array {
    private:
        unsigned int array_size;
        T* array;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"

#endif
