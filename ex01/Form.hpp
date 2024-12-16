#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Form {

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    Form(const std::string &name, int grade);
    Form(const Form& other);
    Form &operator=(const Form& other);
    ~Form();

    std::string const & getName() const;
    bool &getIsSigned() const;
    int const &getGradeSign() const;
    int const &getGradeExecute() const;

    void beSigned(Bureaucrat &b);

    friend std::ostream& operator<<(std::ostream& os, const Form& b);
    
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeSign;
    const int _gradeExecute;


};

#endif