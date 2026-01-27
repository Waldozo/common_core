#include "Serializer.hpp"

int main() {
    Data myData;
    myData.id = 42;
    myData.s1 = "Hello";
    myData.s2 = "Snow";

    Data* ptrOriginal = &myData;
    
    // Serialize
    uintptr_t raw = Serializer::serialize(ptrOriginal);
    
    // Deserialize
    Data* ptrNew = Serializer::deserialize(raw);

    std::cout << "Adresse originale : " << ptrOriginal << std::endl;
    std::cout << "Valeur raw (uintptr_t) : " << raw << std::endl;
    std::cout << "Adresse après désérialisation : " << ptrNew << std::endl;

    if (ptrNew == ptrOriginal) {
        std::cout << "✅ Succès : Les pointeurs sont identiques !" << std::endl;
        std::cout << "Data content : " << ptrNew->s1 << " " << ptrNew->s2 << std::endl;
    } else {
        std::cout << "❌ Erreur : Les pointeurs diffèrent." << std::endl;
    }

    return 0;
}