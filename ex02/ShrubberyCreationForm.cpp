#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "ShrubberyCreationForm Parameterized Constructor Called" << std::endl;   
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream ofs(_target + "_shrubbery");
    if (!ofs) {
        std::cerr << "Error: Could not create file" << std::endl;
        return;
    }
    ofs << "     .        +          .      .\n"
        << "   .            _        .                    .\n"
        << " ,              /;-._,-.____        ,-----.__\n"
        << "((        .    (_:#::_.__/ B  `'-._/ ,.\n"
        << " `                 \\   \\       ,  /#\n"
        << "                     |  |     ,-\n"
        << "                     |  |    (\n"
        << "                     |  |     '-.\n"
        << "                     |  |\n"
        << "                     |  |\n";
    ofs.close();
    std::cout << "ShrubberyCreationForm executed successfully" << std::endl;
}
