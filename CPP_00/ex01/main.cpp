#include "PhoneBook.hpp"

int main()
{
    Contact contact;
    PhoneBook phonebook;
    Contact contact_array[8];
    int i = 0;
    int nb_contacts = 0;
    std::string command;
    while (1)
    {
        std::cout << "Please enter one of this command: ADD, SEARCH, EXIT" << std::endl; 
        std::cin >> command;
        if (command == "ADD")
        {
            contact.get_contact(contact_array[8]);
            if (i >= 8)
            {
                std::cout << "We have erased your oldest contact sorry :p";
                i = 0;
            }
            while(i < 8)
            {
                contact_array[i] = contact;
                i++;
            }
            nb_contacts++;
            std::cout << "Contact added !" << std::endl << std::endl;
        }
        else if (command == "SEARCH")
        {
            phonebook.print_phonebook(&nb_contacts, &contact_array[8]);
                

        }
        else if (command == "EXIT")
        {
            return 0;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
}