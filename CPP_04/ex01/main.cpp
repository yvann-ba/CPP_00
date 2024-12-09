#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }

    std::cout << "-------------------------------------" << std::endl;

    // Deep copy test
    {
        Dog dog1;
        dog1.setIdea(0, "I want to play");
        dog1.setIdea(1, "I want to sleep");

        Dog dog2(dog1); // Copy constructor
        Dog dog3;
        dog3 = dog1; // Assignment operator

        std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;
        std::cout << "dog3 idea[0]: " << dog3.getIdea(0) << std::endl;

        dog1.setIdea(0, "I am hungry now!");

        std::cout << "After modification:" << std::endl;
        std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;
        std::cout << "dog3 idea[0]: " << dog3.getIdea(0) << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    {
        int n = 10;
        Animal* animals[n];

        for (int k = 0; k < n; k++) {
            if (k < n / 2)
                animals[k] = new Dog();
            else
                animals[k] = new Cat();
        }

        Dog *dogPtr = dynamic_cast<Dog*>(animals[0]);
        if (dogPtr) {
            dogPtr->setIdea(0, "Chase cats!");
        }

        for (int k = 0; k < n; k++) {
            delete animals[k];
        }
    }

    return 0;
}
