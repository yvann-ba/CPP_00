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
	std::string message;

	while (true)
	{
		std::cout << "First Name: ";
		if (!std::getline(std::cin, message))
			return;
		message.erase(0, message.find_first_not_of(" \t\n\r\f\v"));
		message.erase(message.find_last_not_of(" \t\n\r\f\v") + 1);
		if (!message.empty())
		{
			set_firstName(message);
			break;
		}
		else
			std::cout << "First Name cannot be empty or whitespace only." << std::endl;
	}
	while (true)
	{
		std::cout << "Last Name: ";
		if (!std::getline(std::cin, message))
			return;
		message.erase(0, message.find_first_not_of(" \t\n\r\f\v"));
		message.erase(message.find_last_not_of(" \t\n\r\f\v") + 1);
		if (!message.empty())
		{
			set_lastName(message);
			break;
		}
		else
			std::cout << "Last Name cannot be empty or whitespace only." << std::endl;
	}
	while (true)
	{
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, message))
			return;
		message.erase(0, message.find_first_not_of(" \t\n\r\f\v"));
		message.erase(message.find_last_not_of(" \t\n\r\f\v") + 1);
		if (!message.empty())
		{
			set_nickname(message);
			break;
		}
		else
			std::cout << "Nickname cannot be empty or whitespace only." << std::endl;
	}
	while (true)
	{
		std::cout << "Phone Number: ";
		if (!std::getline(std::cin, message))
			return;
		message.erase(0, message.find_first_not_of(" \t\n\r\f\v"));
		message.erase(message.find_last_not_of(" \t\n\r\f\v") + 1);
		if (!message.empty())
		{
			set_phoneNumber(message);
			break;
		}
		else
			std::cout << "Phone Number cannot be empty or whitespace only." << std::endl;
	}
	while (true)
	{
		std::cout << "Darkest Secret: ";
		if (!std::getline(std::cin, message))
			return;
		message.erase(0, message.find_first_not_of(" \t\n\r\f\v"));
		message.erase(message.find_last_not_of(" \t\n\r\f\v") + 1);
		if (!message.empty())
		{
			set_darkestSecret(message);
			break;
		}
		else
			std::cout << "Darkest Secret cannot be empty or whitespace only." << std::endl;
	}
}
