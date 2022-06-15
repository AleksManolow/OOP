#ifndef __WARRIOR_H
#define __WARRIOR_H
#include"Hero.h"

class Warrior:public Hero
{
public:
    Warrior();

    virtual void print() const;

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out)const;
};


#endif