#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{
    
}
void PhoneBook::print_phonebook(int nb_contacts, Contact contact[8])
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    if (nb_contacts > 7)
        nb_contacts = 7;
    for(int i = 0; i < nb_contacts; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << contact[i].get_firstName() << "|";
        std::cout << std::setw(10) << contact[i].get_lastName() << "|";
        std::cout << std::setw(10) << contact[i].get_nickname() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Type a contact index for more info" << std::endl;
    
    int i_contact;
    std::cin >> i_contact;
    if (std::cin.fail()) {
        std::cin.clear();
        char c;
        while (std::cin.get(c) && c != '\n');
        std::cout << "Invalid index" << std::endl;
    }
    else if (i_contact > nb_contacts || i_contact == 0 || (i_contact < 1 || i_contact > 8))
        std::cout << "No contact at this index" << std::endl;
    else
    {
        std::cout << "Contact [" << i_contact << "] Info:" << std::endl;
        i_contact -= 1;
        std::cout << "First Name:" << contact[i_contact].get_firstName() << std::endl;
        std::cout << "Last Name:" << contact[i_contact].get_lastName() << std::endl;
        std::cout << "Nickname:" << contact[i_contact].get_nickname() << std::endl;
        std::cout << "Phone Number:" << contact[i_contact].get_phoneNumber() << std::endl;
        std::cout << "Darkest Secret:" << contact[i_contact].get_darkestSecret() << std::endl;
    }
}