#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
    private:
    std::string _fields[5];
    
    public:
        enum Field {
            FIRST_NAME,
            LAST_NAME,
            NICKNAME,
            PHONE_NUMBER,
            DARKEST_SECRET
        };
        
        Contact();
        ~Contact();

        void setField(Field field, const std::string& value);
        std::string getField(Field field) const;
    };
#endif
