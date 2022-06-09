#ifndef __WARRIOR_H
#define __WARRIOR_H
#include"Hero.h"

class Warrior:public Hero
{
public:
    Warrior();

    virtual void print() const;

};


#endif