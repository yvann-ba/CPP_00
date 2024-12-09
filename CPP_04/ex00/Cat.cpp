#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat Default Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other){
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
};

void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}