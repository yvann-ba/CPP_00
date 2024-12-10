#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    if (this != &other)
        AMateria::operator=(other);
    std::cout << "Ice assignement operator called" << std::endl;
    return *this;

}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}