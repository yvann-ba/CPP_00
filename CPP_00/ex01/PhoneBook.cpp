#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _nb_contacts(0), _current_index(0)
{

}

PhoneBook::~PhoneBook()
{
	
}

void PhoneBook::print_phonebook() const
{
	if (_nb_contacts == 0)
	{
		std::cout << "Phonebook is empty. No contacts to display." << std::endl;
		return;
	}
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
		std::cout << std::setw(10) << truncate(_contacts[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Type a contact index for more info: ";

	std::string input;
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "No index entered." << std::endl;
		return;
	}
	if (!isdigit(input[0]))
	{
		std::cout << "Invalid index: not a number." << std::endl;
		return;
	}
	if (input.length() > 1)
	{
		std::cout << "Invalid index:  Index too big" << std::endl;
		return;
	}
	
	int i_contact = input[0] - '0';
	if (i_contact < 1 || i_contact > nb_contacts)
	{
		std::cout << "Invalid index: out of range." << std::endl;
		return;
	}
	if (!std::cin.eof())
	{
		std::cout << "Contact [" << i_contact << "] Info:" << std::endl;
		i_contact -= 1;
		std::cout << "First Name: " << _contacts[i_contact].get_firstName() << std::endl;
		std::cout << "Last Name: " << _contacts[i_contact].get_lastName() << std::endl;
		std::cout << "Nickname: " << _contacts[i_contact].get_nickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[i_contact].get_phoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[i_contact].get_darkestSecret() << std::endl;
	}
}


void PhoneBook::add_contact()
{
	if (_current_index == MAX_CONTACTS)
	{
		std::cout << "Reached maximum contacts. Overwriting the oldest contact from now on" << std::endl;
		_current_index = 0;
	}
	_contacts[_current_index].set_contact();
	_current_index++;
	if (_nb_contacts < MAX_CONTACTS)
		_nb_contacts++;
}
