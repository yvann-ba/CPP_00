#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "Intern.hpp"
int main() {
    Intern intern;
    AForm* form;

    form = intern.makeForm("robotomy request", "Bobby");
    if (form) {
        Bureaucrat captainFlam("captain Flam", 1);
        captainFlam.signForm(*form);
        captainFlam.executeForm(*form);
        delete form;
    }

    form = intern.makeForm("unknow form", "popapo");
    if (form)
        delete form;
    return 0;
}
