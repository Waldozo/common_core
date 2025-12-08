#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Construction/Destruction chaining ===" << std::endl;
    {
        ScavTrap robot1;           // Constructeur par défaut
        ScavTrap robot2("WALL-E"); // Constructeur avec nom

        ClapTrap *test;
        test = new ScavTrap("salut");
        delete test;
        std::cout << "\n=== Test 2: Héritage des fonctions ===" << std::endl;
        robot1.attack("enemy1"); // Fonction redéfinie
        robot1.takeDamage(30);   // Fonction héritée
        robot1.beRepaired(10);   // Fonction héritée

        std::cout << "\n=== Test 3: Fonction spéciale ScavTrap ===" << std::endl;
        robot2.guardGate(); // Fonction unique à ScavTrap

        std::cout << "\n=== Test 4: Valeurs par défaut ScavTrap ===" << std::endl;
        robot2.attack("big enemy"); // Doit faire 20 dégâts

        std::cout << "\n=== Sortie du scope - Destructeurs ===" << std::endl;
    }

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}