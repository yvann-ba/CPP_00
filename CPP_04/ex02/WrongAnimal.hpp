#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const std::string &type);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal &operator=(const WrongAnimal& other);
    ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

#endif