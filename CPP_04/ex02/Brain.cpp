#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
}

Brain::Brain(const Brain& other){
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
};
