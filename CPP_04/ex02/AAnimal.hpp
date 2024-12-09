#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>

class AAnimal 
{
public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal &operator=(const AAnimal& other);
    virtual ~AAnimal();
    virtual void makeSound() const = 0;
    std::string getType() const;
protected:
    std::string type;
};

#endif