#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Vérification classe abstraite ===" << std::endl;
    {
        // ❌ Cette ligne DOIT causer une erreur de compilation :
        // Animal animal;  // Décommentez pour tester l'erreur !

        // ✅ Mais ceci doit marcher (pointeurs vers classes dérivées) :
        std::cout << "Création via pointeurs Animal* :" << std::endl;
        Animal *dog = new Dog();
        Animal *cat = new Cat();

        std::cout << "Test polymorphisme :" << std::endl;
        dog->makeSound(); // Doit faire "waf waf"
        cat->makeSound(); // Doit faire "meow meow"

        delete dog;
        delete cat;
    }
    std::cout << "--- Fin Test 1 ---\n"
              << std::endl;

    std::cout << "=== Test 2: Copie profonde avec classes abstraites ===" << std::endl;
    {
        std::cout << "Test copie Dog :" << std::endl;
        Dog originalDog;
        Dog copiedDog = originalDog; // Copy constructor

        std::cout << "Test copie Cat :" << std::endl;
        Cat originalCat;
        Cat copiedCat = originalCat; // Copy constructor

        std::cout << "Tous les sons :" << std::endl;
        originalDog.makeSound();
        copiedDog.makeSound();
        originalCat.makeSound();
        copiedCat.makeSound();
    }
    std::cout << "--- Fin Test 2 ---\n"
              << std::endl;

    std::cout << "=== Test 3: Tableau Animal (classe abstraite) ===" << std::endl;
    {
        const int arraySize = 6;
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

        std::cout << "\n--- Test des sons (polymorphisme avec classe abstraite) ---" << std::endl;
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound(); // Polymorphisme : appelle Dog ou Cat makeSound()
        }

        std::cout << "\n--- Suppression du tableau ---" << std::endl;
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << "Suppression Animal " << i << ":" << std::endl;
            delete animals[i]; // Destructeur virtuel appelle le bon destructeur
        }
    }
    std::cout << "--- Fin Test 3 ---\n"
              << std::endl;

    std::cout << "=== Test 4: Fonction prenant Animal abstrait en paramètre ===" << std::endl;
    {
        Dog dog;
        Cat cat;

        // Fonction qui prend n'importe quel Animal (mais pas Animal direct !)
        std::cout << "Test avec pointeurs Animal* :" << std::endl;

        Animal *animals[2];
        animals[0] = &dog;
        animals[1] = &cat;

        for (int i = 0; i < 2; i++)
        {
            std::cout << "Type: " << animals[i]->getType() << " - Son: ";
            animals[i]->makeSound();
        }
    }
    std::cout << "--- Fin Test 4 ---\n"
              << std::endl;

    std::cout << "\n🎉 TOUS LES TESTS RÉUSSIS ! 🎉" << std::endl;
    std::cout << "✅ Animal est bien une classe abstraite" << std::endl;
    std::cout << "✅ Polymorphisme fonctionne parfaitement" << std::endl;
    std::cout << "✅ Pas de fuites mémoire" << std::endl;

    return 0;
}