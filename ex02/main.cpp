#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
    try
    {
        Bureaucrat poppey("poppey", 30);
        Form tax("Tax Form", 50, 25);

        std::cout << tax << std::endl;
        poppey.signForm(tax);
        std::cout << tax << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Bureaucrat CaptainFlam("Captain Flam", 50);
    Form SpaceTax("Space Tax form", 20, 15);
    std::cout << SpaceTax << std::endl;
    CaptainFlam.signForm(SpaceTax);
    
    return 0;
}