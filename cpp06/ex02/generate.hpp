#ifndef GENERATE_HPP
# define GENERATE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "Base.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
