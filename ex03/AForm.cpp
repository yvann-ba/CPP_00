#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {
    std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeSign, const int gradeExecute) : _name(name), _isSigned(false),
_gradeSign((gradeSign < 1) ? throw GradeTooHighException() : (gradeSign > 150) ? throw GradeTooLowException() : gradeSign), 
_gradeExecute((gradeExecute < 1) ? throw GradeTooHighException() : (gradeExecute > 150) ? throw GradeTooLowException() : gradeExecute)
{
    std::cout << "AForm Parameterized Constructor Called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {
    std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::string const & AForm::getName() const {
    return _name;
}
bool const &AForm::getIsSigned() const {
    return _isSigned;
}
int const &AForm::getGradeSign() const {
    return _gradeSign;
}
int const &AForm::getGradeExecute() const {
    return _gradeExecute;
}

void AForm::beSigned(Bureaucrat &b) {
    if (_isSigned == true)
        std::cout << "AForm is already signed" << std::endl;
    else if (b.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream&  operator<<(std::ostream& os, const AForm& f) {
    os << "AForm: " << f.getName() << std::endl << 
    "isSigned: " << f._isSigned << std::endl <<
    "grade required to sign it: " << f._gradeSign << std::endl <<
    "grade required to execute it: " << f._gradeExecute  << std::endl;
    return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "the grade is too low to sign the AForm";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: attempt to execute a form that is not signed!";
}