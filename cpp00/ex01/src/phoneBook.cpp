#include "../includes/phoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::printMenu(void) {
    std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
    std::cout << "Avaiable commands:" << std::endl;
    std::cout << "ADD - Save a new contact" << std::endl;
    std::cout << "SEARCH - Display a specific contact" << std::endl;
    std::cout << "EXIT - Exit the program" << std::endl;
}

void PhoneBook::addContact(const Contact &newContact) {
    if (contactCount < 8) {
        contact[contactCount] = newContact;
        contactCount++;
    } else {
        contact[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << (contact[i].getField(Contact::FIRST_NAME).length() > 10
                    ? contact[i].getField(Contact::FIRST_NAME).substr(0, 9) + "."
                    : contact[i].getField(Contact::FIRST_NAME)) << "|"

                  << std::setw(10) << (contact[i].getField(Contact::LAST_NAME).length() > 10
                    ? contact[i].getField(Contact::LAST_NAME).substr(0, 9) + "."
                    : contact[i].getField(Contact::LAST_NAME)) << "|"
                  
                  << std::setw(10) << (contact[i].getField(Contact::NICKNAME).length() > 10
                    ? contact[i].getField(Contact::NICKNAME).substr(0, 9) + "."
                    : contact[i].getField(Contact::NICKNAME)) << std::endl;
    }
}

bool PhoneBook::searchContact(int index) const {
    if (index < 0 || index >= contactCount) {
        std::cout << "Invalid index!" << std::endl;
        return false;
    }

    std::cout << "First Name: " << contact[index].getField(Contact::FIRST_NAME) << std::endl;
    std::cout << "Last Name: " << contact[index].getField(Contact::LAST_NAME) << std::endl;
    std::cout << "Nickname: " << contact[index].getField(Contact::NICKNAME) << std::endl;
    std::cout << "Phone Number: " << contact[index].getField(Contact::PHONE_NUMBER) << std::endl;
    std::cout << "Darkest Secret: " << contact[index].getField(Contact::DARKEST_SECRET) << std::endl;
    return true;
}
    