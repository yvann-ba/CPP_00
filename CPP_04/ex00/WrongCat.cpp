#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat Default Constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other){
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
};

void WrongCat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}