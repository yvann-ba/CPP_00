#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {

public:
    class GradeTooHighException : public std::exception {
    public:    
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat &operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string const & getName() const;
    int const &getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form);
    void executeForm(AForm const &form);

    
private:
    const std::string _name;
    int _grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif