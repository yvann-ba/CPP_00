#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Please enter one of these commands: ADD, SEARCH, EXIT" << std::endl; 
        std::cin >> command;
        if (command == "ADD")
        {
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            phonebook.print_phonebook();
        }
        else if (command == "EXIT")
        {
            return 0;
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }
    }
}