# include "../includes/phoneBook.hpp"
# include <csignal>
# include <cstdlib>
# include <limits>

void _searchContact(PhoneBook &phonebook)
{
    int index;

    phonebook.displayContacts();
    std::cout << "Enter index to view contact details: ";
    while (true) {
        std::cin >> index;

        if (std::cin.eof()) {
            return ;
        }

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        } else {
            std::cin.ignore();
            if (!phonebook.searchContact(index))
            {
                std::cout << "Enter index to view contact details: ";
                continue;
            }
            break;
        }
    }
}

void _addContact(PhoneBook &phonebook) {
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
    phonebook.addContact(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}

int main() {
    PhoneBook phonebook;

    std::string command;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::signal(SIGINT, handleSigInt);
    std::signal(SIGQUIT, handleSigQuit);
    while (true)
    {
        if (std::cin.eof())
            handleEOF();
        phonebook.printMenu();
        std::cout << "> " ;
        if (!std::getline(std::cin, command))
            handleEOF();
        if (command == "ADD")
            _addContact(phonebook); // should ph.add;
        else if (command == "SEARCH")
            _searchContact(phonebook);
        else if (command == "EXIT")
        {
            std::cout << "Thanks for using My Awesome PhoneBook, Goodbye!" << std::endl;
            break ;
        }
        else
            std::cout << "Invalid command! Please try again." << std::endl;
    }
    return (0);
}
