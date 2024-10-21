#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _nb_contacts(0), _current_index(0)
{

}

PhoneBook::~PhoneBook()
{
    
}

std::string truncate(std::string message)
{
    if (message.length() > 10)
    {
        message = message.substr(0, 9);
        message += '.';
    }
    return message;
}

void PhoneBook::print_phonebook() const
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    int nb_contacts = _nb_contacts > MAX_CONTACTS ? MAX_CONTACTS : _nb_contacts;
    for(int i = 0; i < nb_contacts; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << truncate(_contacts[i].get_firstName()) << "|";
        std::cout << std::setw(10) << truncate(_contacts[i].get_lastName()) << "|";
        std::cout << std::setw(10) << truncate(_contacts[i].get_nickname()) << std::endl;
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
    else if (i_contact > nb_contacts || i_contact == 0 || (i_contact < 1 || i_contact > MAX_CONTACTS))
        std::cout << "No contact at this index" << std::endl;
    else
    {
        std::cout << "Contact [" << i_contact << "] Info:" << std::endl;
        i_contact -= 1;
        std::cout << "First Name:" << _contacts[i_contact].get_firstName() << std::endl;
        std::cout << "Last Name:" << _contacts[i_contact].get_lastName() << std::endl;
        std::cout << "Nickname:" << _contacts[i_contact].get_nickname() << std::endl;
        std::cout << "Phone Number:" << _contacts[i_contact].get_phoneNumber() << std::endl;
        std::cout << "Darkest Secret:" << _contacts[i_contact].get_darkestSecret() << std::endl;
    }
}

void PhoneBook::add_contact()
{
    if (_current_index == MAX_CONTACTS)
    {
        std::cout << "Your oldest contact has been removed to add this new one" << std::endl;
        _current_index = 0;
    }
    _contacts[_current_index].set_contact();
    _current_index++;
    if (_nb_contacts < MAX_CONTACTS)
        _nb_contacts++;
    std::cout << "Contact added!" << std::endl << std::endl;
}