# include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other){
    (void) other;
    std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this == &other)
        return *this;
    (void) other;
    std::cout << "Serializer copy assignment operator called" << std::endl;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
