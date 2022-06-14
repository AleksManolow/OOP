#ifndef __SPELL_H
#define __SPELL_H
#include"Treasure.h"

class Spell:public Treasure
{
public:
    Spell();

    virtual void print() const;

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out);

};


#endif