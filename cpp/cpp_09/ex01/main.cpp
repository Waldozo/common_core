#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
    // 1. Vérifier qu'il y a exactement un argument (le nom du programme + l'expression)
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // 2. Instancier ta classe
    RPN rpn;

    // 3. Appeler ta fonction de calcul avec l'argument passé
    // av[1] contient toute la chaîne "3 2 +"
    rpn.execute(av[1]);

    return 0;
}