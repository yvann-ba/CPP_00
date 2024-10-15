# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
//#include "PhoneBook.hpp"

class Contact {
    public:
        Contact();
        ~Contact();
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        void get_contact(Contact contact_array);
};

# endif