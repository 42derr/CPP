# include <iostream>
# include <string>

int main(void) {
    std::string stringBRAIN = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringBRAIN;
    std::string& stringREF = stringBRAIN;

    std::cout << "The memory address of the string variable: " << &stringBRAIN << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "The value of the string variable: " << stringBRAIN << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    return (0);
}