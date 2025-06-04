#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
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

    void addContact(const Contact& newContact);
    void displayContacts() const;
    bool searchContact(int index) const;
    void printMenu(void);
};
#endif