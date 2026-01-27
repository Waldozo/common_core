#include <iostream>
#include <string>
#include "Array.hpp"

void testConst(const Array<int>& a) {
    std::cout << "\n--- Test 6 : Acces en lecture seule (const) ---" << std::endl;
    if (a.size() > 0) {
        std::cout << "Premier element lu via const : " << a[0] << std::endl;
    }
}

int main() {
    // --- TEST 1 : Construction et taille ---
    std::cout << "--- Test 1 : Construction ---" << std::endl;
    Array<int> empty;
    Array<int> numbers(5);

    std::cout << "Taille de 'empty' : " << empty.size() << std::endl;
    std::cout << "Taille de 'numbers' : " << numbers.size() << std::endl;

    // --- TEST 2 : Remplissage et accès ---
    std::cout << "\n--- Test 2 : Remplissage ---" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // --- TEST 3 : Deep Copy (Copie profonde) ---
    std::cout << "\n--- Test 3 : Deep Copy ---" << std::endl;
    Array<int> copy(numbers);
    copy[0] = 999; 

    std::cout << "Original numbers[0] : " << numbers[0] << " (devrait etre 0)" << std::endl;
    std::cout << "Copie copy[0]       : " << copy[0] << " (devrait etre 999)" << std::endl;

    if (numbers[0] != copy[0]) {
        std::cout << "=> Succes : La modification de la copie n'affecte pas l'original !" << std::endl;
    }

    // --- TEST 4 : Exceptions (Hors limites) ---
    std::cout << "\n--- Test 4 : Exceptions ---" << std::endl;
    try {
        std::cout << "Tentative d'acces a l'index 10 (taille 5)..." << std::endl;
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapee : " << e.what() << std::endl;
    }

    // --- TEST 5 : Types complexes (std::string) ---
    std::cout << "\n--- Test 5 : Types complexes ---" << std::endl;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "C++";
    words[2] = "98";

    for (unsigned int i = 0; i < words.size(); i++) {
        std::cout << "words[" << i << "] = " << words[i] << std::endl;
    }

    return 0;

    testConst(numbers);
}