#ifndef __ARMOR_H
#define __ARMOR_H
#include"Treasure.h"

class Armor:public Treasure
{
public:
    Armor();
    Armor(double _percent, String _name);

    virtual void print()const;
    
    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out);
};

#endif