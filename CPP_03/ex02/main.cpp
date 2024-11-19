#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n--- Testing ClapTrap ---" << std::endl;
    ClapTrap clap1("Yvann");
    ClapTrap clap2("Lilien");

    clap1.attack("random npc");
    clap2.takeDamage(5);
    clap2.beRepaired(6);

    ClapTrap clap3(clap1);
    ClapTrap clap4;
    clap4 = clap2;

    std::cout << "\n--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav1("Scavvy");
    scav1.attack("enemy");
    scav1.takeDamage(20);
    scav1.beRepaired(15);
    scav1.guardGate();

    ScavTrap scav2(scav1); 
    ScavTrap scav3;
    scav3 = scav1;

    std::cout << "\n--- Testing FragTrap ---" << std::endl;
    FragTrap frag1("Fraggy");
    frag1.attack("boss enemy");
    frag1.takeDamage(50);
    frag1.beRepaired(30);
    frag1.highFivesGuys();

    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;

    std::cout << "\n--- Object Destruction ---" << std::endl;

    return 0;
}
