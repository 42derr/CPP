# include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = "Some good ideas";
        // std::cout << this->ideas[i] << std::endl;
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other){
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i] + " copied";
        // std::cout << this->ideas[i] << std::endl;
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this == &other)
        return *this;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i]+ " copied";
        // std::cout << this->ideas[i] << std::endl;
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}
