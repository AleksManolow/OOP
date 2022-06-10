#ifndef __ARMOR_H
#define __ARMOR_H
#include"Treasure.h"

class Armor:public Treasure
{
public:
    Armor();
    Armor(double _percent, std::string _name);

    virtual void print()const;
};

#endif