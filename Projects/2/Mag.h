#ifndef __MAG_H
#define __MAG_H
#include"Hero.h"

class Mag:public Hero
{
public:
    Mag();

    virtual void print() const;

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out) const;
};


#endif