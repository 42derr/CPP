# include "PhoneBook.hpp"

int main(int argc, char* argv[]) {
    PhoneBook phonebook;

    (void)argv;
    if (argc > 1) {
        std::cerr << "Usage: ./phoneBook" << std::endl;
        return (1);
    }
    std::string command;
    std::signal(SIGINT, handleSigInt);
    std::signal(SIGQUIT, handleSigQuit);
    while (true)
    {
        if (std::cin.eof())
        {
            std::cout << std::endl << "Caught EOF, Exiting..." << std::endl;
            return (0);
        }
        phonebook.printMenu();
        std::cout << "> " ;
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl << "Caught EOF, Exiting..." << std::endl;
            return (0);
        }
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
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
