#include "Form.hpp"

Form::Form(const std::string &name, int grade) : _name(name){
    std::cout << "Form Default Constructor Called" << std::endl;
    
    if (grade > 150)
        throw Form::GradeTooLowException();
    else if (grade < 1)
        throw Form::GradeTooHighException();
    _grade = grade;
}

Form::Form(const Form& other) {
    std::cout << "Form Copy Constructor called" << std::endl;
    *this = other;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Form::~Form() {
        std::cout << "Form destructor called" << std::endl;
}

std::string const & Form::getName() const {
    return _name;
}

int const & Form::getGrade() const {
    return _grade;
}

std::ostream&  operator<<(std::ostream& os, const Form& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Form::incrementGrade() {
    if (_grade <= 1)
        throw Form::GradeTooHighException();
    _grade--;
}

void Form::decrementGrade() {
    if (_grade >= 150)
        throw Form::GradeTooLowException();
    _grade++;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade is too low!";
}
