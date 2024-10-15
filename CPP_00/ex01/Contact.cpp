#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}
void    Contact::get_contact(Contact contact_array)
{
    std::cout << "First Name:" << std::endl;
    std::cin >> first_name;
    std::cout << "Last Name:" << std::endl;
    std::cin >> last_name;
    std::cout << "Nickname:" << std::endl;
    std::cin >> nickname;
    std::cout << "Phone Number:" << std::endl;
    std::cin >> phone_number;
    std::cout << "Darkest Secret:" << std::endl;
    std::cin >> darkest_secret;
}