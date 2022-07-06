#include"Point.h"
#include<iostream>

void Point::initPoint()
{
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y; 
}
double Point::getX() const
{
    return x;
}
double Point::getY() const
{
    return y;
}