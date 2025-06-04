#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include "contact.hpp"
# include "phoneBookUtils.hpp"

class PhoneBook {
private:
    Contact contact[8];
    int contactCount;
    int oldestIndex;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(void);
    void displayContacts(void) const;
    void searchContact(void);
    void printMenu(void);
};
#endif