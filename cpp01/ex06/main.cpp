# include "harl.hpp"

int main(int argc, char *argv[]) {
    Harl harl;
    if (argc != 2)
    {
        std::cout << "./harlfilter LEVEL" <<std::endl;
        return 1;
    }

    harl.complain(argv[1]);
    return 0;
}