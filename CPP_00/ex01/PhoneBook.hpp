# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    void print_phonebook(int *nb_contacts, Contact contact_array[8]);
private:

};

# endif