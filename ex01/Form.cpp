#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {
    std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(const std::string &name, const int gradeSign, const int gradeExecute) : _name(name), _isSigned(false),
_gradeSign((gradeSign < 1) ? throw GradeTooHighException() : (gradeSign > 150) ? throw GradeTooLowException() : gradeSign), 
_gradeExecute((gradeExecute < 1) ? throw GradeTooHighException() : (gradeExecute > 150) ? throw GradeTooLowException() : gradeExecute)
{
    std::cout << "Form Parameterized Constructor Called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string const & Form::getName() const {
    return _name;
}
bool const &Form::getIsSigned() const {
    return _isSigned;
}
int const &Form::getGradeSign() const {
    return _gradeSign;
}
int const &Form::getGradeExecute() const {
    return _gradeExecute;
}

std::ostream&  operator<<(std::ostream& os, const Form& f) {
    os << "Form: " << f.getName() << std::endl << 
    "isSigned: " << f._isSigned << std::endl <<
    "grade required to sign it: " << f._gradeSign << std::endl <<
    "grade required to execute it: " << f._gradeExecute  << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "the grade is too low to sign the form";
}

void Form::beSigned(Bureaucrat &b) {
    if (_isSigned == true)
        std::cout << "Form is already signed" << std::endl;
    else if (b.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}