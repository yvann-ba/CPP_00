#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
    std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern Copy Constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string requests[] = { "shrubbery request", "robotomy request", "presidential request"};
    AForm *forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    AForm *_return = 0;
    for (int i = 0; i < 3; i++) {
        if (formName == requests[i])
            _return = forms[i];
        else
            delete forms[i];
    }
    if (_return)
        std::cout << "Intern creates " << formName << " for " << target << std::endl;
    else
        std::cout << "Intern can't create a " << formName << std::endl;
    return (_return);
}
