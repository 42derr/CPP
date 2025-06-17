#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main()
{
    std::string testCases[] = {
        "a",
        "z",
        "0",
        "42",
        "-42",
        "2147483647",
        "-2147483648",
        "2147483648",
        "3.14",
        "-3.14",
        "1.0f",
        "-1.0f",
        "nan",
        "nanf",
        "+inf",
        "+inff",
        "-inf",
        "-inff",
        ".",
        "++42",
        "42f3",
        "abc",
        " ",
        "",
        "+",
        "-",
        ".98",
        "5f",
        "1e3",
        "1e-3"
    };

    size_t n = sizeof(testCases) / sizeof(testCases[0]);

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "Input: \"" << testCases[i] << "\"\n";
        ScalarConverter::convert(testCases[i]);
        std::cout << "----------------------\n";
    }

    return 0;
}
