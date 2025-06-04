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

void PhoneBook::addContact(void) {
    std::string details[5];
    const std::string prompts[5] = {
        "Enter first name: ",
        "Enter last name: ",
        "Enter nickname: ",
        "Enter phone number: ",
        "Enter darkest secret: "
    }; 
    int cur = 0;
    while (cur < 5)
    {
        std::cout << prompts[cur];
        std::getline(std::cin, details[cur]);

        if (std::cin.eof()) {
            return ;
        }
        details[cur] = trim(details[cur]);
        if (details[cur].empty())
        {
            std::cout << "Field cannot be empty! Please try again." << std::endl;
            continue;
        }
        if (cur == Contact::PHONE_NUMBER)
        {
            if (!isValidPhoneNumber(details[cur]))
                continue;
        }
        cur++;
    }
    Contact newContact;
    newContact.setField(Contact::FIRST_NAME ,details[0]);
    newContact.setField(Contact::LAST_NAME, details[1]);
    newContact.setField(Contact::NICKNAME, details[2]);
    newContact.setField(Contact::PHONE_NUMBER, details[3]);
    newContact.setField(Contact::DARKEST_SECRET, details[4]);
    if (contactCount < 8) {
        contact[contactCount] = newContact;
        contactCount++;
    } else {
        contact[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact(void) {
    int index;

    this->displayContacts();
    std::cout << "Enter index to view contact details: ";
    while (true) {
        std::cin >> index;
        if (std::cin.eof()) {
            return ;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a valid number: ";
        } else {
            std::cin.ignore();
            if (index < 0 || index >= contactCount) {
                std::cout << "Index out of range. Enter a valid number:" << std::endl;
                continue;
            }
            else
            {
                std::cout << "First Name: " << contact[index].getField(Contact::FIRST_NAME) << std::endl;
                std::cout << "Last Name: " << contact[index].getField(Contact::LAST_NAME) << std::endl;
                std::cout << "Nickname: " << contact[index].getField(Contact::NICKNAME) << std::endl;
                std::cout << "Phone Number: " << contact[index].getField(Contact::PHONE_NUMBER) << std::endl;
                std::cout << "Darkest Secret: " << contact[index].getField(Contact::DARKEST_SECRET) << std::endl;
            }
            break;
        }
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
