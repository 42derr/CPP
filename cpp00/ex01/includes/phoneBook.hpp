#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include "contact.hpp"

class PhoneBook {
private:
    Contact contact[8];
    int contactCount;
    int oldestIndex;

public:
    PhoneBook();
    ~PhoneBook();

    void _addContact(const Contact& newContact);
    void _displayContacts() const;
    bool _searchContact(int index) const;
};
#endif