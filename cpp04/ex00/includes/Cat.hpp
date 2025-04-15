#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat : public Animal {
    private:

    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        
        void  makeSound(void) const;
};

#endif
