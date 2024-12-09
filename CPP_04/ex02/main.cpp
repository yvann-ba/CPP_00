#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // AAnimal* animal = new AAnimal();

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << dog->getType() << " makes sound: ";
    dog->makeSound();

    std::cout << cat->getType() << " makes sound: ";
    cat->makeSound();

    delete dog;
    delete cat;
    
    return 0;
}
