#include "Point.hpp"

// Retourne la composante Z du produit vectoriel entre (v1) et (v2)
Fixed crossProduct(const Point &v1_start, const Point &v1_end, const Point &v2_start, const Point &v2_end)
{
    Fixed v1_x = v1_end.getX() - v1_start.getX();
    Fixed v1_y = v1_end.getY() - v1_start.getY();

    Fixed v2_x = v2_end.getX() - v2_start.getX();
    Fixed v2_y = v2_end.getY() - v2_start.getY();

    return (v1_x * v2_y - v1_y * v2_x);
}

// Retourne true si le point est STRICTEMENT a l'interieur du triangle
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // (cote AB du triangle)
    Fixed cross1 = crossProduct(a, b, a, point);
    // (cote BC du triangle)
    Fixed cross2 = crossProduct(b, c, b, point);
    //(cote CA du triangle)
    Fixed cross3 = crossProduct(c, a, c, point);

    // verification (aucun point sur une arete ou un sommet)
    if (cross1 == Fixed(0) || cross2 == Fixed(0) || cross3 == Fixed(0))
        return false;

    // produit scalaire nul = point sur une arete ou un sommet
    bool allPositive = (cross1 > Fixed(0)) && (cross2 > Fixed(0)) && (cross3 > Fixed(0));
    bool allNegative = (cross1 < Fixed(0)) && (cross2 < Fixed(0)) && (cross3 < Fixed(0));
    
    return (allPositive || allNegative);
}