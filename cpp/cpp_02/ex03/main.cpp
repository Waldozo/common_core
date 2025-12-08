#include "Point.hpp"
#include <iostream>

// Déclaration de la fonction bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

void testBSP(Point const a, Point const b, Point const c, Point const point, const std::string &description)
{
    bool result = bsp(a, b, c, point);
    std::cout << description << ": ";
    if (result)
        std::cout << "INSIDE";
    else
        std::cout << "OUTSIDE";
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "=== TESTS BSP (Binary Space Partitioning) ===" << std::endl;
    std::cout << "Triangle ABC: A(0,0), B(10,0), C(5,10)" << std::endl;

    // Définition du triangle
    Point a(0.0f, 0.0f);  // Sommet A
    Point b(10.0f, 0.0f); // Sommet B
    Point c(5.0f, 10.0f); // Sommet C

    std::cout << "\n--- Points à l'INTÉRIEUR (devrait retourner true) ---" << std::endl;
    testBSP(a, b, c, Point(5.0f, 2.0f), "Point au centre (5,2)");
    testBSP(a, b, c, Point(3.0f, 1.0f), "Point vers A (3,1)");
    testBSP(a, b, c, Point(7.0f, 1.0f), "Point vers B (7,1)");
    testBSP(a, b, c, Point(5.0f, 8.0f), "Point vers C (5,8)");

    std::cout << "\n--- Points à l'EXTÉRIEUR (devrait retourner false) ---" << std::endl;
    testBSP(a, b, c, Point(-1.0f, 1.0f), "Point à gauche (-1,1)");
    testBSP(a, b, c, Point(11.0f, 1.0f), "Point à droite (11,1)");
    testBSP(a, b, c, Point(5.0f, -1.0f), "Point en bas (5,-1)");
    testBSP(a, b, c, Point(5.0f, 11.0f), "Point en haut (5,11)");

    std::cout << "\n--- Points sur les ARÊTES (devrait retourner false) ---" << std::endl;
    testBSP(a, b, c, Point(5.0f, 0.0f), "Point sur arête AB (5,0)");
    testBSP(a, b, c, Point(2.5f, 5.0f), "Point sur arête AC (2.5,5)");
    testBSP(a, b, c, Point(7.5f, 5.0f), "Point sur arête BC (7.5,5)");

    std::cout << "\n--- Points sur les SOMMETS (devrait retourner false) ---" << std::endl;
    testBSP(a, b, c, Point(0.0f, 0.0f), "Sommet A (0,0)");
    testBSP(a, b, c, Point(10.0f, 0.0f), "Sommet B (10,0)");
    testBSP(a, b, c, Point(5.0f, 10.0f), "Sommet C (5,10)");

    std::cout << "\n=== TRIANGLE DIFFÉRENT ===" << std::endl;
    std::cout << "Triangle DEF: D(-2,-2), E(6,2), F(2,8)" << std::endl;

    Point d(-2.0f, -2.0f);
    Point e(6.0f, 2.0f);
    Point f(2.0f, 8.0f);

    testBSP(d, e, f, Point(2.0f, 2.0f), "Point au centre (2,2)");
    testBSP(d, e, f, Point(0.0f, 0.0f), "Point (0,0)");
    testBSP(d, e, f, Point(10.0f, 10.0f), "Point extérieur (10,10)");

    return 0;
}