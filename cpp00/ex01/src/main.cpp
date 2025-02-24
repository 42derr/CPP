# include "../includes/phoneBook.hpp"
# include <csignal>
# include <cstdlib>
# include <limits>

void handleSigInt(int sig)
{
    std::cout << std::endl << "Caught SIGINT, Exiting..." << std::endl;
    std::exit(128 + sig);
}

void handleSigQuit(int sig)
{
    std::cout << std::endl << "Caught SIGQUIT, Exiting..." << std::endl;
    std::exit(128 + sig);
}

void handleEOF(void)
{
    std::cout << std::endl << "Caught EOF, Exiting..." << std::endl;
    std::exit(0);
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\v\f");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r\v\f");
    return str.substr(first, last - first + 1);
}

void printMenu(void)
{
    std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
    std::cout << "Avaiable commands:" << std::endl;
    std::cout << "ADD - Save a new contact" << std::endl;
    std::cout << "SEARCH - Display a specific contact" << std::endl;
    std::cout << "EXIT - Exit the program" << std::endl;
}

bool isValidPhoneNumber(const std::string& phoneNumber) {
    size_t i = 0;
    if (phoneNumber[0] == '+') {
        i = 1;
    }
    if (phoneNumber.length() == i) {
        return false;
    }
    while (i < phoneNumber.length())
    {
        if (!std::isdigit(phoneNumber[i])) {
            std::cout << "Please enter phone number with digits only." << std::endl;
            return false;
        }
        i++;
    }
    return true;
}

void _searchContact(PhoneBook &phonebook)
{
    int index;

    phonebook._displayContacts();
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
            if (!phonebook._searchContact(index))
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
    
    phonebook._addContact(newContact);
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
        if (std::cin.eof()) {
            handleEOF();
        }
        printMenu();
        std::cout << "> " ;
        if (!std::getline(std::cin, command))
        {
            handleEOF();
        }
        if (command == "ADD")
        {
            _addContact(phonebook);
        }
        else if (command == "SEARCH")
        {
            _searchContact(phonebook);
        }
        else if (command == "EXIT")
        {
            std::cout << "Thanks for using My Awesome PhoneBook, Goodbye!" << std::endl;
            break ;
        }
        else
        {
            std::cout << "Invalid command! Please try again." << std::endl;
        }
    }
    return (0);
}
