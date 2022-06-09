#ifndef __ARMOR_H
#define __ARMOR_H
#include"Treasure.h"

class Armor:public Treasure
{
public:
    Armor();

    virtual void print()const;
};

#endif