#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound(); // will output the dog sound
        i->makeSound(); // will output the cat sound
        meta->makeSound(); // will output the animal sound

        delete meta;
        delete j;
        delete i;
    }

    std::cout << "----------------------------------------" << std::endl;

    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the WrongAnimal sound, not the WrongCat sound
        meta->makeSound();
        delete meta;
        delete i;
    }

    return 0;
}
