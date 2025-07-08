# include "generate.hpp"

Base * generate(void)
{
    static bool seeded = false;
    if (seeded == false)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int randomNumber = std::rand() % 3;
    switch (randomNumber) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    }
    catch (std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch (std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch (std::exception& e) {}

    std::cout << "Unknown\n";
}

