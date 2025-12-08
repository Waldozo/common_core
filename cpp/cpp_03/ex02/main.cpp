#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Construction/Destruction chaining ===" << std::endl;
    {
        FragTrap robot1;            // Constructeur par défaut
        FragTrap robot2("Optimus"); // Constructeur avec nom

        std::cout << "\n=== Test 2: Héritage des fonctions ===" << std::endl;
        robot1.attack("Decepticon"); // Fonction redéfinie (30 dégâts)
        robot1.takeDamage(40);       // Fonction héritée
        robot1.beRepaired(20);       // Fonction héritée

        std::cout << "\n=== Test 3: Fonction spéciale FragTrap ===" << std::endl;
        robot2.highFivesGuys(); // Fonction unique à FragTrap
        robot1.highFivesGuys(); // Test avec robot1 aussi

        std::cout << "\n=== Test 4: Valeurs par défaut FragTrap (100 HP, 100 énergie, 30 dégâts) ===" << std::endl;
        robot2.attack("Megatron");   // Doit faire 30 dégâts
        robot2.attack("Starscream"); // Encore 30 dégâts

        std::cout << "\n=== Test 5: Résistance FragTrap (100 HP) ===" << std::endl;
        robot2.takeDamage(50);      // Gros dégâts
        robot2.attack("Soundwave"); // Peut encore attaquer
        robot2.beRepaired(30);      // Se répare

        std::cout << "\n=== Test 6: Épuisement d'énergie (100 actions possibles) ===" << std::endl;
        std::cout << "Attaques multiples..." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            robot1.attack("dummy" + std::to_string(i));
        }

        std::cout << "Réparations multiples..." << std::endl;
        for (int i = 0; i < 3; i++)
        {
            robot1.beRepaired(5);
        }

        std::cout << "\n=== Test 7: FragTrap quasi-mort ===" << std::endl;
        robot1.takeDamage(95);       // Presque mort
        robot1.attack("last enemy"); // Peut encore attaquer avec 5 HP
        robot1.takeDamage(10);       // Maintenant mort
        robot1.attack("ghost");      // Ne peut plus attaquer
        robot1.beRepaired(10);       // Ne peut plus se réparer

        std::cout << "\n=== Test 8: Celebration finale ===" << std::endl;
        robot2.highFivesGuys(); // Célébration finale

        std::cout << "\n=== Sortie du scope - Destructeurs ===" << std::endl;
    }

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}