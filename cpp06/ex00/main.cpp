#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2)
    {
        std::cout << "./convert [args]" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return(0);
}

// int main()
// {
//     std::string testCases[] = {
//         "a",
//         "z",
//         "0",
//         "42",
//         "-42",
//         "2147483647",
//         "-2147483648",
//         "2147483648",
//         "340282000000000000000000000000000000000",
//         "-340282000000000000000000000000000000000",
//         "340283000000000000000000000000000000000",
//         "3.14",
//         "-3.14",
//         "1.0f",
//         "-1.0f",
//         "nan",
//         "nanf",
//         "+inf",
//         "+inff",
//         "-inf",
//         "-inff",
//         ".",
//         "++42",
//         "42f3",
//         "abc",
//         " ",
//         "",
//         "+",
//         "-",
//         ".98",
//         "5f",
//         "1e3",
//         "1e-3",
//     };

//     std::cout << std::numeric_limits<float>::max() << std::endl;

//     size_t n = sizeof(testCases) / sizeof(testCases[0]);

//     for (size_t i = 0; i < n; ++i)
//     {
//         std::cout << "Input: \"" << testCases[i] << "\"\n";
//         ScalarConverter::convert(testCases[i]);
//         std::cout << "----------------------\n";
//     }

//     return 0;
// }
