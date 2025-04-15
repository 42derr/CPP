#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal {
    private:

    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        
        void  makeSound(void) const;
};

#endif
