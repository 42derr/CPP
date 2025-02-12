#include "phoneBook.hpp"

class Contact{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

class PhoneBook{
    public:
        int index;
        Contact myContact[9];
};


int main(void)
{
    PhoneBook myPhoneBook;
	std::string command;

    myPhoneBook.index = 0;

    while (1)
    {
	    std::cout << "Enter your commands:\n";
	    std::cin >> command;
        if (command == "ADD")
        {
            Contact myContact;

            std::cout << "Enter your first name:\n";
            std::cin >> myContact.first_name;
            std::cout << "Enter your last name:\n";
            std::cin >> myContact.last_name;
            std::cout << "Enter your nickname:\n";
            std::cin >> myContact.nickname;
            std::cout << "Enter your phone number:\n";
            std::cin >> myContact.phone_number;
            std::cout << "Enter your darkest secret:\n";
            std::cin >> myContact.darkest_secret;

            myPhoneBook.myContact[myPhoneBook.index] = myContact;
            if (myPhoneBook.index > 8)
            {
                myPhoneBook.index = 0;
            }
            else
            {
                myPhoneBook.index++;
            }
        }
        else if (command == "SEARCH")
        {
            int i = 0;
            int spaces = 0;
            int length = 0;
            std::string index;

            std::cout << "---------------------------------------------\n";
            std::cout << "|     index|first name| last name|  nickname|\n";
            std::cout << "---------------------------------------------\n";
            while (i < 9)
            {
                // std::cout << "|          |          |          |          |\n";
                std::cout << "|";
                std::cout << "         ";
                std::cout << i;
                std::cout << "|";
                length = myPhoneBook.myContact[i].first_name.length();
                spaces = 10 - length;
                while (spaces--)
                {
                    std::cout << " ";
                }
                std::cout << myPhoneBook.myContact[i].first_name;
                std::cout << "|";
                length = myPhoneBook.myContact[i].last_name.length();
                spaces = 10 - length;
                while (spaces--)
                {
                    std::cout << " ";
                }
                std::cout << myPhoneBook.myContact[i].last_name;
                std::cout << "|";
                length = myPhoneBook.myContact[i].nickname.length();
                spaces = 10 - length;
                while (spaces--)
                {
                    std::cout << " ";
                }
                std::cout << myPhoneBook.myContact[i].nickname;
                std::cout << "|";
                std::cout << "\n";
                // handle if more than 10 character
                i++;
            }
            std::cout << "---------------------------------------------\n";
            std::cout << "Enter index of the entry to display:\n";
            // while (1)
            // {
            //     std::cin >> index;
            //     // if (!isdigit(index[1]))
            //     // {

            //     // }
            // }
        }
        else if (command == "EXIT")
        {
	        std::cout << "Thanks for using our service\n";
            return (0);
        }
        else
        {
	        std::cout << "Invalid commands, We only have ADD, SEARCH, and EXIT\n";
        }
    }
    return (0);
}