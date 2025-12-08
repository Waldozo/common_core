#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
   
    std::cout << "=== Test: Tableau Animal ===" << std::endl;
    {
        const int arraySize = 10;
        Animal *animals[arraySize];

        std::cout << "\n--- Creation du tableau ---" << std::endl;
        for (int i = 0; i < arraySize; i++)
        {
            if (i < arraySize / 2)
            {
                std::cout << "Creation Dog " << i << ":" << std::endl;
                animals[i] = new Dog();
            }
            else
            {
                std::cout << "Creation Cat " << i << ":" << std::endl;
                animals[i] = new Cat();
            }
        }

        std::cout << "\n--- Test des sons ---" << std::endl;
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
        }

        std::cout << "\n--- Suppression du tableau ---" << std::endl;
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << "Suppression Animal " << i << ":" << std::endl;
            delete animals[i];
        }
    }

    std::cout << "=== Test 2: Test de copie ===" << std::endl;
    {
        std::cout << "Test avec Cat:" << std::endl;
        Cat cat1;
        Cat cat2 = cat1; // Copy constructor
        Cat cat3;
        cat3 = cat1; // Operateur d'assignation

        std::cout << "Tous les chats font leur bruit:" << std::endl;
        cat1.makeSound();
        cat2.makeSound();
        cat3.makeSound();
    }
    std::cout << "=== Test 3: Test Brain indépendant ===" << std::endl;
    {
        std::cout << "Creation de Brain indépendants:" << std::endl;
        Brain brain1;
        Brain brain2 = brain1; // Copy constructor Brain
        Brain brain3;
        brain3 = brain1; // Operateur d'assignation Brain
        std::cout << "Tous les Brain créés avec succès" << std::endl;
    }

    std::cout << "\n🎉 TOUS LES TESTS TERMINÉS ! 🎉" << std::endl;
    std::cout << "Si aucun crash et tous les destructeurs sont appelés = SUCCESS!" << std::endl;

    return 0;
}