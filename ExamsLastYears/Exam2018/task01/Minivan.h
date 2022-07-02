#ifndef __MINIVAN_H
#define __MINIVAN_H
#include<iostream>
#include"Vehicle.h"
class Minivan:public Vehicle
{
public:
    Minivan();
    Minivan(char* );
    Minivan(const Minivan&);
    Minivan& operator=(const Minivan& );

};


#endif