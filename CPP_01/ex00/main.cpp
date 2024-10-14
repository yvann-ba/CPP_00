#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a zombie with newZombie" << std::endl;
    Zombie *heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    std::cout << std::endl;

    std::cout << "Creating a zombie with randomChump" << std::endl;
    randomChump("Stack Zombie");

    std::cout << std::endl;
    delete heapZombie;
}