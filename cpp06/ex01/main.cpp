#include "Serializer.hpp"
#include <iostream>

int main() {
    Data original;
    original.x = 42;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&original);

    // Deserialize back to pointer
    Data* copy = Serializer::deserialize(raw);

    // Check if the deserialized pointer is the same
    std::cout << "Original address:    " << &original << std::endl;
    std::cout << "Deserialized address: " << copy << std::endl;
    std::cout << "Value: " << copy->x << std::endl;

    if (copy == &original)
        std::cout << "✅ Deserialization successful!" << std::endl;
    else
        std::cout << "❌ Deserialization failed!" << std::endl;

    return 0;
}
