#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void Contact::set_firstName(std::string firstName) {
    this->_firstName = firstName;
}
void Contact::set_lastName(std::string lastName) {
    this->_lastName = lastName;
}
void Contact::set_nickname(std::string nickname) {
    this->_nickname = nickname;
}
void Contact::set_phoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}
void Contact::set_darkestSecret(std::string darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

std::string Contact::get_firstName() const {
    return this->_firstName;
}
std::string Contact::get_lastName() const {
    return this->_lastName;
}
std::string Contact::get_nickname() const {
    return this->_nickname;
}
std::string Contact::get_phoneNumber() const {
    return this->_phoneNumber;
}
std::string Contact::get_darkestSecret() const {
    return this->_darkestSecret;
}


void    Contact::set_contact()
{
    std::string message = "";

    std::cout << "First Name: ";
    std::cin >> message;
    set_firstName(message);
    std::cout << "Last Name: ";
    std::cin >> message;
    set_lastName(message);
    std::cout << "Nickname: ";
    std::cin >> message;
    set_nickname(message);
    std::cout << "Phone Number :";
    std::cin >> message;
    set_phoneNumber(message);
    std::cout << "Darkest Secret: ";
    std::cin >> message;
    set_darkestSecret(message);
}