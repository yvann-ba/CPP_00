#include "Zombie.hpp"

int main()
{
    int nbZombies = 10;

    std::cout << "Initialization of the zombies horde" << std::endl;
    Zombie *zombies = zombieHorde(nbZombies, "Steve");
    
    std::cout << std::endl;

    std::cout << "Annoucing the zombies" << std::endl;
    for(int i = 0; i < nbZombies; i++)
        zombies[i].announce();

    std::cout << std::endl;

    std::cout << "Kill the zombies to avoid memory leaks" << std::endl;
    delete [] zombies;
}