#ifndef __PERSON_H
#define __PERSON_H
#include"Hero.h"

class Person:public Hero
{
public:
    Person();

    virtual void print() const;
};


#endif