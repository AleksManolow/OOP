#ifndef __VEHICLE_H
#define __VEHICLE_H
#include<iostream>

class Vehicle
{
private:
    char* brand;
    int maxSpeed;

    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Vehicle();
    Vehicle(char* , int );
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle& );
    virtual ~Vehicle();
};


#endif