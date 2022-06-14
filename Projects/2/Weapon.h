#ifndef __WEAPON_H
#define __WEAPON_H
#include"Treasure.h"

class Weapon:public Treasure
{
public:
    Weapon();

    virtual void print() const;

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out);
};


#endif