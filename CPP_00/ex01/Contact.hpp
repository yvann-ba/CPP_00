# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        ~Contact();
        void set_firstName(std::string firstName);
        void set_lastName(std::string lastName);
        void set_nickname(std::string nickname);
        void set_phoneNumber(std::string phoneNumber);
        void set_darkestSecret(std::string darkestSecret);

        std::string get_firstName() const;
        std::string get_lastName() const;
        std::string get_nickname() const;
        std::string get_phoneNumber() const;
        std::string get_darkestSecret() const;
        void set_contact();
};

# endif