#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat Default Constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*(other.brain));

}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;

        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
};

void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100)
        brain->ideas[index] = idea;
}

std::string Cat::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return (brain->ideas[index]);
    return ("");
}