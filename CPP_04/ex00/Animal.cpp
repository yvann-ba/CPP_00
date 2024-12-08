#include "Animal.hpp"

Animal::Animal() : type("") {
    type = "";
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal Copy Constructor called" << std::endl;
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