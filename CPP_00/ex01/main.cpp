#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		if (std::cin.eof()==0)
			std::cout << "Please enter one of these commands: ADD, SEARCH, EXIT" << std::endl; 
		if (!std::getline(std::cin, command))
			break;
		if (command == "EXIT")
			return 0;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.print_phonebook();
		else if (!command.empty())
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}