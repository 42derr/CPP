#include "Span.hpp"
#include <iostream>

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

int main() {
    Span sp(10000);  // span with max 10,000 elements

    // Create a large vector of random integers
    std::vector<int> largeVector;
    for (int i = 1; i <= 10000; ++i)
        largeVector.push_back(i);

    try {
        // Add all elements of the vector in one go
        sp.addRange(largeVector.begin(), largeVector.end());

        // Test the span
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
