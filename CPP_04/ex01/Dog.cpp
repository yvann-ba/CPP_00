#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() {
    std::cout << "Default Dog Constructor Called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog Copy Constructor Called" << std::endl;
    this->brain = new Brain(*(other.brain));
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog Copy assignement operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destrcutor Called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100)
        brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return (brain->ideas[index]);
    return ("");
}