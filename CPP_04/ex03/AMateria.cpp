#include "AMateria.hpp"

AMateria::AMateria() : type("default") {
    //std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
    //std::cout << "AMateria Parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
    //std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    (void)other;
    //std::cout << "AMateria assignement operator called" << std::endl;
    return *this;

}

AMateria::~AMateria() {
    //std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "* uses generic Materia on " << target.getName() << " *" << std::endl; 
}