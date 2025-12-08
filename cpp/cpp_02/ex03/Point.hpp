#pragma once
#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
    Point &operator=(const Point &other);
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};