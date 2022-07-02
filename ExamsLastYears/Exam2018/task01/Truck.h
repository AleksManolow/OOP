#ifndef __Truck_H
#define __Truck_H
#include<iostream>
#include"Vehicle.h"
class Truck:public Vehicle
{
public:
    Truck();
    Truck(char* );
    Truck(const Truck&);
    Truck& operator=(const Truck& );

};


#endif