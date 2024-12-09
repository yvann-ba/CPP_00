#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal Default Constructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "AAnimal Copy Constructor called" << std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal copy assignment operator called." << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
        std::cout << "AAnimal destructor called." << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal base sound" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}