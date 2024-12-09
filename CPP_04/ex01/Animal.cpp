#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called." << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
        std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal base sound" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}