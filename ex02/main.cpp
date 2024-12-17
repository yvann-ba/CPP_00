#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("Bender");
        PresidentialPardonForm presForm("Marvin");

        bob.signForm(shrubForm);
        bob.executeForm(shrubForm);

        bob.signForm(roboForm);
        bob.executeForm(roboForm);

        bob.signForm(presForm);
        bob.executeForm(presForm);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
