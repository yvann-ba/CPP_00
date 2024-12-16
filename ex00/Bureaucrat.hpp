#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        std::string _name;
        int _grade;
    public:
        std::string const & getName() const;
        int const &getGrade() const;

};
#endif