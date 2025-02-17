#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Default Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Copy assignement operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destrcutor Called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}