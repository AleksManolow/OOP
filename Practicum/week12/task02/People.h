#ifndef PEOPLE_H
#define PEOPLE_H
#include<iostream>
#include<cstring>
class People
{
private:
    char* EGN;
    char* name;

    char* allocateMemory(char* s);
public:
    People();
    People(char* , char* );
    People(const People& );
    People& operator=(const People& );
    ~People();

    void print();
};

#endif