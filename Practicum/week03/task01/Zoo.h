#ifndef ZOO_H
#define ZOO_H
#include<iostream>
#include"Animal.h"

struct Zoo
{
    char* mName;
    Animal* mAnimals;
    unsigned mCount;
    int mCapacity;

    void initialize();
    void deleteDynamic();
    void loadFromStream(std::istream&); 
    void writeToStream(std::ostream&);
    bool hasType(Type type);
};

#endif