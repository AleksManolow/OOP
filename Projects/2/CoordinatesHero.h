#ifndef __COORDINATESHERO_H
#define __COORDINATESHERO_H
#include<iostream>

class CoordinatesHero
{
private:
    int x;
    int y;
public:
    CoordinatesHero();
    
    int getX()const;
    int getY()const;

    void setX(int _x);
    void setY(int _y);

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out) const;
};

#endif