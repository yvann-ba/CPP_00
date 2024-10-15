#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{
    
}
void PhoneBook::print_phonebook(int *nb_contacts, Contact contact_array[8])
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    if (*nb_contacts >= 8)
        *nb_contacts = 8;

    for(int i = 0; i < *nb_contacts; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << contact_array[i].first_name << "|";
        std::cout << std::setw(10) << contact_array[i].last_name << "|";
        std::cout << std::setw(10) << contact_array[i].nickname << std::endl;
    }

    // std::cout << std::endl;
    // std::cout << "Type a contact index for more info" << std::endl;
    
    // int i_contact;
    // std::cin >> i_contact;

    // if (i_contact > *nb_contacts || i_contact == 0)
    //     std::cout << "No contact at this index" << std::endl;
    // else
    // {
    //     std::cout << "Contact [" << i_contact << "] Info:" << std::endl;
    //     std::cout << "First Name:" << contact.first_name << std::endl;
    //     std::cout << "Last Name:" << contact.last_name << std::endl;
    //     std::cout << "Nickname:" << contact.nickname << std::endl;
    //     std::cout << "Phone Number:" << contact.phone_number << std::endl;
    //     std::cout << "Darkest Secret:" << contact.darkest_secret << std::endl;
    // }
}