#include "PhoneBook.hpp"

int main()
{
    Contact contact[8];
    PhoneBook phonebook;
    std::string command;
    int i = 0;
    int nb_contacts = 0;
    while (1)
    {
        std::cout << "Please enter one of this command: ADD, SEARCH, EXIT" << std::endl; 
        std::cin >> command;
        if (command == "ADD")
        {
            if (i == 8)
            {
                std::cout << "Your oldest contact have been removed, to add this new one" << std::endl;
                i = 0;
            }
            contact[i].set_contact();
            i++;
            nb_contacts++;
            std::cout << "Contact added !" << std::endl << std::endl;
        }
        else if (command == "SEARCH")
        {
            phonebook.print_phonebook(nb_contacts, contact);
                

        }
        else if (command == "EXIT")
        {
            return 0;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}