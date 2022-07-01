#ifndef __PERSON_H
#define __PERSON_H
#include<iostream>
#include<cstring>
class Person
{
private:
    char* name;

    char* allocateMemory(char* );
    void deleteMemory(char* );
public:
    Person();
    Person(char* );
    Person(const Person& );
    Person& operator=(const Person& );
    ~Person();

    char* getName()const {   return name;    }
};

#endif