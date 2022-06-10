#ifndef __MONSTER_H
#define __MONSTER_H
#include"Armor.h"

class Monster
{
private:
    double force;
    double mana;
    double health;

    Armor armor;
public:
    Monster();
    void print() const;
};



#endif