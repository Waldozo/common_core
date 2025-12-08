#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Constructeurs ===" << std::endl;
    ClapTrap robot1;         // Constructeur par défaut
    ClapTrap robot2("R2D2"); // Constructeur avec nom

    std::cout << "\n=== Test 2: Attaques ===" << std::endl;
    robot1.attack("enemy1");
    robot2.attack("enemy2");

    std::cout << "\n=== Test 3: Prendre des dégâts ===" << std::endl;
    robot1.takeDamage(3);
    robot2.takeDamage(5);

    std::cout << "\n=== Test 4: Réparation ===" << std::endl;
    robot1.beRepaired(2);
    robot2.beRepaired(4);

    std::cout << "\n=== Test 5: Épuiser l'énergie ===" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        robot1.attack("dummy");
    }

    std::cout << "\n=== Test 6: Robot avec 0 santé ===" << std::endl;
    robot2.takeDamage(20); // Dégâts énormes pour tuer le robot
    robot2.attack("enemy3");
    robot2.beRepaired(5);

    std::cout << "\n=== Fin du programme - Destructeurs ===" << std::endl;
    return 0;
}