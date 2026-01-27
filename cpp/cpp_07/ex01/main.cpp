#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

void increment(int &n)
{
    n++;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};

    // Test 1 : Affichage simple
    std::cout << "Affichage du tableau :" << std::endl;
    iter(tab, 5, print<int>); // Ici on instancie explicitement le template print pour int

    // Test 2 : Modification
    std::cout << "Incrémentation..." << std::endl;
    iter(tab, 5, increment);

    // Test 3 : Affichage après modif
    iter(tab, 5, print<int>);

    return 0;
}