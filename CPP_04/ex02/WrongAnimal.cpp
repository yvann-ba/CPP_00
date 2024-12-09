#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
        std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal base sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}