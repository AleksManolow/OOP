#ifndef __CAR_H
#define __CAR_H
#include<iostream>
#include"Vehicle.h"
class Car:public Vehicle
{
public:
    Car();
    Car(char* );
    Car(const Car&);
    Car& operator=(const Car& );

};


#endif