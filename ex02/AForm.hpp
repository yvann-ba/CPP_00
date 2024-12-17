#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class AForm {

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    AForm();
    AForm(const std::string &name, const int gradeSign, 
    const int gradeExecute);
    AForm(const AForm& other);
    AForm &operator=(const AForm& other);
    virtual ~AForm();

    std::string const & getName() const;

    bool const &getIsSigned() const;
    
    int const &getGradeSign() const;
    int const &getGradeExecute() const;

    void beSigned(Bureaucrat &b);

    virtual void execute(Bureaucrat const &executor) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const AForm& f);
    
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeSign;
    const int _gradeExecute;


};

#endif