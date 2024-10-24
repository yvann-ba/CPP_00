# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "utils.hpp"
# define MAX_CONTACTS 8

class PhoneBook {
private:
	Contact _contacts[MAX_CONTACTS];
	int _nb_contacts;
	int _current_index;
public:
	PhoneBook();
	~PhoneBook();
	void print_phonebook() const;
	void add_contact();
};

# endif