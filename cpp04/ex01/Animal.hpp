#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

        virtual void  makeSound(void) const;
        std::string getType(void) const;
};

#endif
