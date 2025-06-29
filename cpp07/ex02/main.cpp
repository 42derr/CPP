#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Test copy constructor and assignment inside scope
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Copy constructor and assignment tested successfully\n";
    }

    // Verify numbers and mirror have same values
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "Data consistency test passed\n";

    // Test out-of-bounds negative index
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test out-of-bounds positive index (equal to size)
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Refill numbers with new random values
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "Array modified successfully after exception tests\n";

    delete [] mirror;
    return 0;
}
