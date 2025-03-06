# ifndef HARL_CPP
# define HARL_CPP

# include <iostream>

class Harl{
    private:
        void (Harl::*complaints[4])();
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};

#endif

