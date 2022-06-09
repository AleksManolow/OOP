#ifndef __SPELL_H
#define __SPELL_H
#include"Treasure.h"

class Spell:public Treasure
{
public:
    Spell();

    virtual void print() const;

};


#endif