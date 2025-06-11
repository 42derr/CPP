#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "Amateria.hpp"

class Cure : public AMateria
{
    private:
    public:
        Cure();
        ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        AMateria* clone() const;
};

#endif
